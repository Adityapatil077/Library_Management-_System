#include <string.h>
#include <iostream>
using namespace std;
class StringOperation
{
protected:
    char str[90];

public:
    StringOperation(char str[])
    {
        strcpy(this->str, str);
    }
    virtual void performOperation() = 0;
};

class ToConvertToUpper : public StringOperation
{
    int len;

public:
    ToConvertToUpper(char str[]) : StringOperation(str)
    {
    }
    void performOperation()
    {
        len = strlen(str);

        cout << "\nString==" << str;
        cout << "\nlength===" << len;
        for (int i = 0; str[i] != '\0'; i++)
        {
            str[i] = str[i] - 32;
            cout << "\t" << str[i];
        }
        cout << "\n\nUpper String : " << str;
    }
};
class MaxRepatativeChar : public StringOperation
{
private:
    int count, temp = 0;
    char p;

public:
    MaxRepatativeChar(char str[]) : StringOperation(str)
    {
    }
    void performOperation()
    {
        for (int i = 0; str[i] != '\0'; i++)
        {
            count = 0;
            for (int j = i + 1; str[j] != '\0'; j++)
            {
                if (str[i] == str[j])
                {
                    count++;
                }
            }
            if (count > temp)
            {
                temp = count;
                p = str[i];
            }
        }
        cout << "\nMaximum Repatative Character is : " << p;
    }
};
class WordReverse : public StringOperation
{
private:
    int len = 0, i;
    char temp;

public:
    WordReverse(char str[]) : StringOperation(str)
    {
    }
    void performOperation()
    {

        for (i = 0; str[i] != '\0'; i++)
        {
            len++;
        }
        str[i] = '\0';
        int mid = len / 2;
        int end = len - 1;
        for (int i = 0; i < mid; i++, end--)
        {
            temp = str[i];
            str[i] = str[end];
            str[end] = temp;
        }
        cout << "\n\nReverse String is : " << str;
    }
};
int main()
{
    char str[90];
    cout << "\nEnter a string : ";
    gets(str);

    ToConvertToUpper u(str);
    u.performOperation();
    MaxRepatativeChar m(str);
    m.performOperation();
    WordReverse r(str);
    r.performOperation();
    return 0;
}