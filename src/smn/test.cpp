#include <iostream>
#include <commander.hpp>

void assert (bool worked) {
    if (!worked)
        std::cout << "didn't work well \n";
}

int main () {
    std::vector <const char*> args {"smoothiemaker", "-shakeBananas", "-allowMistakes", "-sprinkleChocolate", "brown"};
    CMD::commander a(5, args.data());
    assert (a.isFlagSet("-allowMistakes") == true);
    assert (a.isFlagSet("-stirIngredients") == false);
    assert (a.getFlagValue("-sprinkleChocolate") == "brown");
    assert (a.getEverythingFrom("-allowMistakes") == "-sprinkleChocolate brown ");
    assert (a.getEverythingFromTo("-shakeBananas", "-sprinkleChocolate") == "-allowMistakes ");
    assert (a.getFlagPosition("-allowMistakes") == 2);
    assert (a[2] == "-allowMistakes");
    assert (a.getAllFlagsLike(std::regex ("-\\w*")) == std::vector<std::string> {"-shakeBananas", "-allowMistakes", "-sprinkleChocolate"});
    assert (a.getAllFlagsUnlike(std::regex ("-\\w*")) == std::vector<std::string> {"smoothiemaker", "brown"});
    for (auto i : a) {
        std::cout << i << " ";
    }
    std::cout << "\n";
}