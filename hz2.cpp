#include <iostream>

std::string sum_of_strings(std::string line1, std::string line2)
{
    std::string final_line(line1.length() + 1, ' ');
    int dd = 0;
    for(int i = line1.length() - 1; i >= 0; --i)
    {
        char c1, c2;
        c1 = line1[i];
        c2 = line2[i];
        short arc = (c1 + c2 + dd - 96) % 10 + 48;
        char sim = arc;
        final_line[i] = sim;
        dd = (c1 + c2 + dd - 96) / 10;
    }
    return final_line;
}

int main () {
    std::string line1, line2, final_line;
    std::cin >> line1;
    std::cin >> line2;
    final_line = sum_of_strings(line1, line2);
    std::cout << final_line;
    return 0;
}
