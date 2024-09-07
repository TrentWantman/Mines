#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>
using std::unordered_map;
using std::string;

struct multiplier
{

    multiplier()
    = default;

    double static multi (int gems, int mines)
    {
        if (mines == 0)
        {
            return 1;
        }
        if (mines == 0)
        {
            return 1;
        }
        else if (gems == 1)
        {
            if (mines == 1)
            {
                return 1.03;
            }
            else if (mines == 2)
            {
                return 1.08;
            }
            else if (mines == 3)
            {
                return 1.12;
            }
            else if (mines == 4)
            {
                return 1.18;
            }
            else if (mines == 5)
            {
                return 1.24;
            }
            else if (mines == 6)
            {
                return 1.30;
            }
            else if (mines == 7)
            {
                return 1.37;
            }
            else if (mines == 8)
            {
                return 1.46;
            }
            else if (mines == 9)
            {
                return 1.55;
            }
            else if (mines == 10)
            {
                return 1.65;
            }
            else if (mines == 11)
            {
                return 1.77;
            }
            else if (mines == 12)
            {
                return 1.90;
            }
            else if (mines == 13)
            {
                return 2.06;
            }
            else if (mines == 14)
            {
                return 2.25;
            }
            else if (mines == 15)
            {
                return 2.47;
            }
            else if (mines == 16)
            {
                return 2.75;
            }
            else if (mines == 17)
            {
                return 3.09;
            }
            else if (mines == 18)
            {
                return 3.54;
            }
            else if (mines == 19)
            {
                return 4.12;
            }
            else if (mines == 20)
            {
                return 4.95;
            }
            else if (mines == 21)
            {
                return 6.19;
            }
            else if (mines == 22)
            {
                return 8.25;
            }
            else if (mines == 23)
            {
                return 12.37;
            }
            else if (mines == 24)
            {
                return 24.75;
            }
        }

        else if (gems == 2)
        {
            if (mines == 1)
            {
                return 1.08;
            }
            else if (mines == 2)
            {
                return 1.17;
            }
            else if (mines == 3)
            {
                return 1.29;
            }
            else if (mines == 4)
            {
                return 1.41;
            }
            else if (mines == 5)
            {
                return 1.56;
            }
            else if (mines == 6)
            {
                return 1.74;
            }
            else if (mines == 7)
            {
                return 1.94;
            }
            else if (mines == 8)
            {
                return 2.18;
            }
            else if (mines == 9)
            {
                return 2.47;
            }
            else if (mines == 10)
            {
                return 2.83;
            }
            else if (mines == 11)
            {
                return 3.26;
            }
            else if (mines == 12)
            {
                return 3.81;
            }
            else if (mines == 13)
            {
                return 4.50;
            }
            else if (mines == 14)
            {
                return 5.40;
            }
            else if (mines == 15)
            {
                return 6.60;
            }
            else if (mines == 16)
            {
                return 8.25;
            }
            else if (mines == 17)
            {
                return 10.61;
            }
            else if (mines == 18)
            {
                return 14.14;
            }
            else if (mines == 19)
            {
                return 19.80;
            }
            else if (mines == 20)
            {
                return 29.70;
            }
            else if (mines == 21)
            {
                return 49.50;
            }
            else if (mines == 22)
            {
                return 99.0;
            }
            else if (mines == 23)
            {
                return 297.0;
            }
        }
        else if (gems == 3)
        {
            if (mines == 1)
            {
                return 1.12;
            }
            else if (mines == 2)
            {
                return 1.29;
            }
            else if (mines == 3)
            {
                return 1.48;
            }
            else if (mines == 4)
            {
                return 1.71;
            }
            else if (mines == 5)
            {
                return 2;
            }
            else if (mines == 6)
            {
                return 2.35;
            }
            else if (mines == 7)
            {
                return 2.79;
            }
            else if (mines == 8)
            {
                return 3.35;
            }
            else if (mines == 9)
            {
                return 4.07;
            }
            else if (mines == 10)
            {
                return 5;
            }
            else if (mines == 11)
            {
                return 6.26;
            }
            else if (mines == 12)
            {
                return 7.96;
            }
            else if (mines == 13)
            {
                return 10.35;
            }
            else if (mines == 14)
            {
                return 13.80;
            }
            else if (mines == 15)
            {
                return 18.97;
            }
            else if (mines == 16)
            {
                return 27.11;
            }
            else if (mines == 17)
            {
                return 40.66;
            }
            else if (mines == 18)
            {
                return 65.06;
            }
            else if (mines == 19)
            {
                return 113.85;
            }
            else if (mines == 20)
            {
                return 227.70;
            }
            else if (mines == 21)
            {
                return 569.25;
            }
            else if (mines == 22)
            {
                return 2277;
            }
        }
        else if (gems == 4)
        {
            if (mines == 1)
            {
                return 1.18;
            }
            else if (mines == 2)
            {
                return 1.41;
            }
            else if (mines == 3)
            {
                return 1.71;
            }
            else if (mines == 4)
            {
                return 2.09;
            }
            else if (mines == 5)
            {
                return 2.58;
            }
            else if (mines == 6)
            {
                return 3.23;
            }
            else if (mines == 7)
            {
                return 4.09;
            }
            else if (mines == 8)
            {
                return 5.26;
            }
            else if (mines == 9)
            {
                return 6.88;
            }
            else if (mines == 10)
            {
                return 9.17;
            }
            else if (mines == 11)
            {
                return 12.51;
            }
            else if (mines == 12)
            {
                return 17.52;
            }
            else if (mines == 13)
            {
                return 25.30;
            }
            else if (mines == 14)
            {
                return 37.95;
            }
            else if (mines == 15)
            {
                return 59.64;
            }
            else if (mines == 16)
            {
                return 99.39;
            }
            else if (mines == 17)
            {
                return 178.91;
            }
            else if (mines == 18)
            {
                return 357.81;
            }
            else if (mines == 19)
            {
                return 834.90;
            }
            else if (mines == 20)
            {
                return 2504.70;
            }
            else if (mines == 21)
            {
                return 12523.50;
            }
        }
        else if (gems == 5)
        {
            if (mines == 1)
            {
                return 1.24;
            }
            else if (mines == 2)
            {
                return 1.56;
            }
            else if (mines == 3)
            {
                return 2;
            }
            else if (mines == 4)
            {
                return 2.58;
            }
            else if (mines == 5)
            {
                return 3.39;
            }
            else if (mines == 6)
            {
                return 4.52;
            }
            else if (mines == 7)
            {
                return 6.14;
            }
            else if (mines == 8)
            {
                return 8.50;
            }
            else if (mines == 9)
            {
                return 12.04;
            }
            else if (mines == 10)
            {
                return 17.52;
            }
            else if (mines == 11)
            {
                return 26.27;
            }
            else if (mines == 12)
            {
                return 40.87;
            }
            else if (mines == 13)
            {
                return 66.41;
            }
            else if (mines == 14)
            {
                return 113.85;
            }
            else if (mines == 15)
            {
                return 208.72;
            }
            else if (mines == 16)
            {
                return 417.45;
            }
            else if (mines == 17)
            {
                return 939.26;
            }
            else if (mines == 18)
            {
                return 2504.70;
            }
            else if (mines == 19)
            {
                return 8766.45;
            }
            else if (mines == 20)
            {
                return 52598.70;
            }
        }
        else if (gems == 6)
        {
            if (mines == 1)
            {
                return 1.3;
            }
            else if (mines == 2)
            {
                return 1.74;
            }
            else if (mines == 3)
            {
                return 2.35;
            }
            else if (mines == 4)
            {
                return 3.23;
            }
            else if (mines == 5)
            {
                return 4.52;
            }
            else if (mines == 6)
            {
                return 6.46;
            }
            else if (mines == 7)
            {
                return 9.44;
            }
            else if (mines == 8)
            {
                return 14.17;
            }
            else if (mines == 9)
            {
                return 21.89;
            }
            else if (mines == 10)
            {
                return 35.03;
            }
            else if (mines == 11)
            {
                return 58.38;
            }
            else if (mines == 12)
            {
                return 102.17;
            }
            else if (mines == 13)
            {
                return 189.75;
            }
            else if (mines == 14)
            {
                return 379.50;
            }
            else if (mines == 15)
            {
                return 834.90;
            }
            else if (mines == 16)
            {
                return 2087.25;
            }
            else if (mines == 17)
            {
                return 6261.75;
            }
            else if (mines == 18)
            {
                return 25047;
            }
            else if (mines == 19)
            {
                return 175329;
            }
        }
        else if (gems == 7)
        {
            if (mines == 1)
            {
                return 1.37;
            }
            else if (mines == 2)
            {
                return 1.94;
            }
            else if (mines == 3)
            {
                return 2.79;
            }
            else if (mines == 4)
            {
                return 4.09;
            }
            else if (mines == 5)
            {
                return 6.14;
            }
            else if (mines == 6)
            {
                return 9.44;
            }
            else if (mines == 7)
            {
                return 14.95;
            }
            else if (mines == 8)
            {
                return 24.47;
            }
            else if (mines == 9)
            {
                return 41.60;
            }
            else if (mines == 10)
            {
                return 73.95;
            }
            else if (mines == 11)
            {
                return 138.66;
            }
            else if (mines == 12)
            {
                return 277.33;
            }
            else if (mines == 13)
            {
                return 600.87;
            }
            else if (mines == 14)
            {
                return 1442.10;
            }
            else if (mines == 15)
            {
                return 3965.77;
            }
            else if (mines == 16)
            {
                return 13219.25;
            }
            else if (mines == 17)
            {
                return 59486.62;
            }
            else if (mines == 18)
            {
                return 475893;
            }
        }
    }
};