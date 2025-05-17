#include <iostream>
#include <string>

// Интерфейс стратегии
class PaymentStrategy {
public:
    virtual void pay(int amount) = 0;
    virtual ~PaymentStrategy() = default;
};

// Конкретная стратегия 1
class CreditCardPayment : public PaymentStrategy {
    std::string cardNumber;
public:
    CreditCardPayment(const std::string& number) : cardNumber(number) {}
    void pay(int amount) override {
        std::cout << "Оплата картой " << cardNumber << ": $" << amount << "\n";
    }
};

// Конкретная стратегия 2
class PayPalPayment : public PaymentStrategy {
    std::string email;
public:
    PayPalPayment(const std::string& mail) : email(mail) {}
    void pay(int amount) override {
        std::cout << "Оплата через PayPal: " << email << ", сумма: $" << amount << "\n";
    }
};

// Контекст
class ShoppingCart {
    PaymentStrategy* strategy;
public:
    void setPaymentStrategy(PaymentStrategy* s) {
        strategy = s;
    }

    void checkout(int total) {
        strategy->pay(total);
    }
};

int main() {
    ShoppingCart cart;

    CreditCardPayment cc("1234-5678-9012-3456");
    PayPalPayment pp("user@example.com");

    cart.setPaymentStrategy(&cc);
    cart.checkout(100);

    cart.setPaymentStrategy(&pp);
    cart.checkout(200);

    return 0;
}
