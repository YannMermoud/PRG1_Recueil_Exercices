#include <array>
#include <iostream>
#include <string>

// Define a class that acts as a function object for the manipulator
class Bracketed {
   public:
    // Constructor to store the bracket characters
    Bracketed(const std::string& left, const std::string& right)
        : left_(left), right_(right) {}

    // Overload the output operator to work with std::ostream
    friend std::ostream& operator<<(std::ostream& os, const Bracketed& manip) {
        return os << manip.left_ << manip.text_ << manip.right_;
    }

    // Operator() to set the text inside the brackets
    Bracketed& operator()(const std::string& text) {
        text_ = text;
        return *this;
    }

   private:
    std::string left_, right_;
    std::string text_;
};

// Function to create a Bracketed manipulator
Bracketed brackets(const std::string& left, const std::string& right) {
    return Bracketed(left, right);
}

std::ostream& endLine(std::ostream& os) { return os << " haha \n"; }

int main() {
    // Use the custom manipulator
    std::cout << brackets("( ", " )")("Hello") << endLine
              << brackets("[ ", " ]")("World") << endLine;

    std::array<int, 5> a{1, 2, 3, 4, 5};

    for (int& i : a) {
        i *= i;
    }

    return 0;
}
