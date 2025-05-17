#include <gtest/gtest.h>
#include <thread>
#include <vector>
#include "../src/filesystem.hpp"

TEST(MultithreadTest, ConcurrentAccessIsSafe) {
    Disk disk("MainDisk");
    disk.children.push_back(std::make_shared<TextFile>("file1.txt"));
    disk.children.push_back(std::make_shared<BinaryFile>("data.bin"));

    struct CountingVisitor : FileVisitor {
        int count = 0;
        void visit(Disk&) override { ++count; }
        void visit(Folder&) override { ++count; }
        void visit(TextFile&) override { ++count; }
        void visit(BinaryFile&) override { ++count; }
    };

    auto run_visitor = [&disk]() {
        for (int i = 0; i < 100; ++i) {
            CountingVisitor visitor;
            disk.accept(visitor);
            EXPECT_GE(visitor.count, 2); // минимум 2 элемента в диске
        }
    };

    std::vector<std::thread> threads;
    for (int i = 0; i < 4; ++i) {
        threads.emplace_back(run_visitor);
    }

    for (auto& t : threads) {
        t.join();
    }
}
