#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

enum enCharType { SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4, Mixed = 5 };

void vValidation(int& Number)
{
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "It must be a \"NUMBER\" : ";
		cin >> Number;
	}
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void vNumberZone(int& Number, int From, int To)
{
	while (Number > To || Number < From)
	{
		cout << "The Number must be (" << From << "-" << To << ") : ";
		cin >> Number;
		vValidation(Number);
	}
}

int iReadPositiveNumber(string Text)
{
    int Num;
    do{
        cout << Text;
        cin >> Num;
        vValidation(Num);
    } while (Num < 1);

    return Num;
}

int iGetRandNum(int From, int To)
{
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
}

bool bContinueProject(string Text)
{
    char Continue = ' ';
    do{
        cout << Text;
        cin >> Continue;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (!(Continue == 'y' || Continue == 'Y' || Continue == 'n' || Continue == 'N'));

    if (Continue == 'y' || Continue == 'Y')
        return 1;
    else
        return 0;
}

char cGetRandomChar(enCharType CharType)
{
    if (CharType == enCharType::CapitalLetter)
        return char(iGetRandNum(97, 122));
    else if (CharType == enCharType::SmallLetter)
        return char(iGetRandNum(65, 90));
    else if (CharType == enCharType::SpecialCharacter)
        return char(iGetRandNum(33, 47));
    else if (CharType == enCharType::Digit)
        return char(iGetRandNum(48, 57));
    else
        return cGetRandomChar((enCharType)iGetRandNum(1, 4));
}

enCharType iReadCharType()
{
    int CharType;

    cout << "[1] Capital Letter\n";
    cout << "[2] Small Letter\n";
    cout << "[3] Special Character\n";
    cout << "[4] Digit\n";
    cout << "[5] Mixed\n";
    cout << "Enter character type: ";
    cin >> CharType;
    vValidation(CharType);
    vNumberZone(CharType, 1, 5);

    return (enCharType)CharType;
}

string sgGetRandWord(int Length, enCharType CharType)
{
    string Word = "";

    for (int i = 1; i <= Length; i++)
        Word += cGetRandomChar(CharType);

    return Word;
}

string sgGetRandKey(int NumOfWords, int WordLength, enCharType CharType)
{
    string Key = "";

    for (int i = 1; i <= NumOfWords; i++)
    {
        Key += sgGetRandWord(WordLength, CharType);

        if (i < NumOfWords)
            Key += "-";
    }

    return Key;
}

void vGetArray(string Arr[100], int NumOfElements, int NumOfWords, int WordLength, enCharType CharType)
{
    for (int i = 0; i < NumOfElements; i++)
    {
        Arr[i] = sgGetRandKey(NumOfWords, WordLength, CharType);
    }
}

void vPrintArray(string Arr[100], int NumOfElements)
{
    string Space;
    for (int i = 0; i < NumOfElements; i++)
    {
        if (i + 1 < 10)  Space = "]  : ";
        else if (i < 100) Space = "] : ";
             else         Space = "] : ";
        cout << "Array [" << i + 1 << Space << Arr[i] << endl;
    }
}

void vGenerateRandomKeys()
{
    string Array[100];
    int NumOfElements = iReadPositiveNumber("Please, Enter the number of elements : "); \
        vNumberZone(NumOfElements, 1, 100);
    int NumOfWords = iReadPositiveNumber("Please, Enter the number of words : ");
        vNumberZone(NumOfWords, 1, 100);
    int WordLength = iReadPositiveNumber("Please, Enter the Length of word : ");
        vNumberZone(WordLength, 1, 100);
    enCharType CharType = iReadCharType();


    vGetArray(Array, NumOfElements, NumOfWords, WordLength, CharType);

    cout << "\nArray elements: \n";
    vPrintArray(Array, NumOfElements);
    cout << "\n------------------------------------------\n";
}

void vGenerateRandomKeysScreen()
{
    do {
        vGenerateRandomKeys();
    } while (bContinueProject("\nDo you want to Continue?... (y/n): "));
}

int main(){
    vGenerateRandomKeysScreen();
}