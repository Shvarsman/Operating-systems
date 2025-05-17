#pragma once
#include <string>
#include <vector>
#include <memory>
#include <mutex>

// === Интерфейс посетителя ===
class FileVisitor {
public:
    virtual ~FileVisitor() = default;
    virtual void visit(class Disk& disk) = 0;
    virtual void visit(class Folder& folder) = 0;
    virtual void visit(class TextFile& file) = 0;
    virtual void visit(class BinaryFile& file) = 0;
};

// === Базовый интерфейс узла файловой системы ===
struct FileSystemNode {
    virtual ~FileSystemNode() = default;
    virtual void accept(FileVisitor& visitor) = 0;
};

// === Конкретные типы узлов ===
struct Disk : public FileSystemNode {
    std::string name;
    std::vector<std::shared_ptr<FileSystemNode>> children;

    explicit Disk(const std::string& name) : name(name) {}

    void accept(FileVisitor& visitor) override;
};

struct Folder : public FileSystemNode {
    std::string name;
    std::vector<std::shared_ptr<FileSystemNode>> children;

    explicit Folder(const std::string& name) : name(name) {}

    void accept(FileVisitor& visitor) override;
};

struct TextFile : public FileSystemNode {
    std::string name;

    explicit TextFile(const std::string& name) : name(name) {}
    void accept(FileVisitor& visitor) override;
};

struct BinaryFile : public FileSystemNode {
    std::string name;

    explicit BinaryFile(const std::string& name) : name(name) {}
    void accept(FileVisitor& visitor) override;
};

// === Реализация методов accept ===
inline void Disk::accept(FileVisitor& visitor) { visitor.visit(*this); }
inline void Folder::accept(FileVisitor& visitor) { visitor.visit(*this); }
inline void TextFile::accept(FileVisitor& visitor) { visitor.visit(*this); }
inline void BinaryFile::accept(FileVisitor& visitor) { visitor.visit(*this); }

// === Шаблонная стратегия синхронизации ===
template <typename MutexType = std::mutex>
class SynchronizedNode : public FileSystemNode {
    std::shared_ptr<FileSystemNode> node;
    mutable MutexType mtx;

public:
    template <typename T, typename... Args>
    explicit SynchronizedNode(Args&&... args)
        : node(std::make_shared<T>(std::forward<Args>(args)...)) {}

    void accept(FileVisitor& visitor) override {
        std::lock_guard lock(mtx);
        node->accept(visitor);
    }
};
