#include <iostream>
#include <limits>
using namespace std;

bool IsKPeriodic(string& str, int k)
{
    if (k <= 0)
        throw invalid_argument("Invalid k value");
    if ((int)str.length() < k)
        return false;
    else if ((int)str.length() == k)
        return true;

    char subStr[k];
    for (int i = 0; i < k; i++)
    {
        subStr[i] = str[i];
    }
    

    for (int i = k, j = 0; i < (int)str.length(); i ++, j = (j + 1)%k)
    {
        if (str[i] != subStr[j])
            return false;        
    }
    return true;
}

void ClearConsoleBuffer()
{
	if (std::cin.fail()) 		
		std::cin.clear();		
    if (cin.peek() == '\n')
	    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() 
{
    setlocale(LC_ALL, "");
    cout << string('=', 20) << endl;
    while (true)
    {        
        string input;
        int k;
        cout << "Введите строку или 'q' для выхода из программы" << endl;

        ClearConsoleBuffer();
        getline(cin, input);

        if (input == "q")
            break;
        else
        {
            cout << "Введите период: ";
            cin >> k;
            bool res = IsKPeriodic(input, k);
            cout << "Строка '" << input << "' " << (res ? "кратна " : "не кратна ") << k << endl << endl;
        }        
    }    
    cout << "Пока!" << std::endl;
    return 0;
}