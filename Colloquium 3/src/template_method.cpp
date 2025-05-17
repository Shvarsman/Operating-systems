#include <iostream>

// Абстрактный класс с шаблонным методом
class Game {
public:
    virtual void initialize() = 0;
    virtual void startPlay() = 0;
    virtual void endPlay() = 0;

    // Шаблонный метод
    void play() {
        initialize();
        startPlay();
        endPlay();
    }
};

// Конкретный класс 1
class Cricket : public Game {
public:
    void initialize() override {
        std::cout << "Cricket: Подготовка поля\n";
    }

    void startPlay() override {
        std::cout << "Cricket: Начало игры\n";
    }

    void endPlay() override {
        std::cout << "Cricket: Игра окончена\n";
    }
};

// Конкретный класс 2
class Football : public Game {
public:
    void initialize() override {
        std::cout << "Football: Подготовка мяча и поля\n";
    }

    void startPlay() override {
        std::cout << "Football: Матч начался\n";
    }

    void endPlay() override {
        std::cout << "Football: Матч окончен\n";
    }
};

int main() {
    Game* game;

    game = new Cricket();
    game->play();

    std::cout << "\n";

    game = new Football();
    game->play();

    delete game;
    return 0;
}
