#include <iostream>
#include <vector>
#include <memory>

// Интерфейс команды
class Command {
public:
    virtual void execute() = 0;
    virtual ~Command() = default;
};

// Получатель
class Light {
public:
    void turnOn() {
        std::cout << "Свет включён\n";
    }
    void turnOff() {
        std::cout << "Свет выключен\n";
    }
};

// Конкретная команда
class LightOnCommand : public Command {
    Light& light;
public:
    LightOnCommand(Light& l) : light(l) {}
    void execute() override {
        light.turnOn();
    }
};

class LightOffCommand : public Command {
    Light& light;
public:
    LightOffCommand(Light& l) : light(l) {}
    void execute() override {
        light.turnOff();
    }
};

// Инициатор
class RemoteControl {
    std::vector<std::shared_ptr<Command>> commands;
public:
    void addCommand(std::shared_ptr<Command> cmd) {
        commands.push_back(cmd);
    }

    void pressButton() {
        for (const auto& cmd : commands)
            cmd->execute();
    }
};

int main() {
    Light livingRoomLight;
    Light kitchenLight;

    auto lightOn1 = std::make_shared<LightOnCommand>(livingRoomLight);
    auto lightOn2 = std::make_shared<LightOnCommand>(kitchenLight);

    RemoteControl rc;
    rc.addCommand(lightOn1);
    rc.addCommand(lightOn2);

    std::cout << "Нажата кнопка:\n";
    rc.pressButton();

    return 0;
}
