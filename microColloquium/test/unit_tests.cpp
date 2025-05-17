#include <gtest/gtest.h>
#include "../src/filesystem.hpp"

TEST(FileSystemTest, AcceptVisitor) {
    TextFile file("test.txt");

    struct TestVisitor : FileVisitor {
        bool visited = false;
        void visit(Disk&) override {}
        void visit(Folder&) override {}
        void visit(TextFile& f) override { visited = true; }
        void visit(BinaryFile&) override {}
    } visitor;

    file.accept(visitor);
    EXPECT_TRUE(visitor.visited);
}

TEST(FileSystemTest, VisitorVisitsAllTypes) {
    Disk disk("MainDisk");
    disk.children.push_back(std::make_shared<Folder>("Home"));
    disk.children.push_back(std::make_shared<TextFile>("file.txt"));
    disk.children.push_back(std::make_shared<BinaryFile>("data.bin"));

    struct CountingVisitor : FileVisitor {
        int disk_count = 0;
        int folder_count = 0;
        int text_file_count = 0;
        int binary_file_count = 0;

        void visit(Disk&) override { ++disk_count; }
        void visit(Folder&) override { ++folder_count; }
        void visit(TextFile&) override { ++text_file_count; }
        void visit(BinaryFile&) override { ++binary_file_count; }
    } visitor;

    disk.accept(visitor);

    EXPECT_EQ(visitor.disk_count, 1);
    EXPECT_EQ(visitor.folder_count, 1);
    EXPECT_EQ(visitor.text_file_count, 1);
    EXPECT_EQ(visitor.binary_file_count, 1);
}
