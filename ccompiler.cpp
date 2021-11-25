#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>
#include <QDebug>
#include <iostream>
#define Var 1;
#define Keyword 2;

using namespace std;

vector<string> keywords = {"main", "if", "then", "while", "do", "static", "defualt",
                           "do", "int", "double", "struct", "break", "else", "long",
                           "swtich", "case", "typedf", "char", "return", "const", "float",
                           "short", "continue", "for", "void", "sizeof", "printf"};
vector<string> tk_type = {"Num", "Fun", "Sys", "Glo", "Loc", "Id",
                          "Char", "Else", "Enum", "If", "Int", "Return", "Sizeof", "While",
                          "Assign", "Cond", "Lor", "Lan", "Or", "Xor", "And", "Eq", "Ne", "Lt", "Gt", "Le", "Ge", "Shl", "Shr", "Add", "Sub", "Mul", "Div", "Mod", "Inc", "Dec", "Brak", "can't recognize"};

// fields of identifier

enum Token_type
{
    Num = 128,
    Fun,
    Sys,
    Glo,
    Loc,
    Id,
    Char,
    Else,
    Enum,
    If,
    Int,
    Return,
    Sizeof,
    While,
    Assign,
    Cond,
    Lor,
    Lan,
    Or,
    Xor,
    And,
    Eq,
    Ne,
    Lt,
    Gt,
    Le,
    Ge,
    Shl,
    Shr,
    Add,
    Sub,
    Mul,
    Div,
    Mod,
    Inc,
    Dec,
    Brak
};

// fields of identifier
struct identifier
{
    int token;
    string name = "Num";
    int Class;
    int type;
    int value;
    int Bclass;
    int Btype;
    int Bvalue;
};

vector<identifier> symbol_table;
void make_table()
{
    for (auto i = keywords.begin(); i != keywords.end(); i++)
    {
        struct identifier temp;
        temp.token = Keyword;
        temp.name = *i;
        symbol_table.push_back(temp);
    }
}

void tokenize(string code)
{
    make_table();
    int line = 1;
    int token = 0;
    auto i = code.begin();
    while (i != code.end())
    {
        fflush(stdout);
        if (*i == '\n')
        {
            line++;
            i++;
            continue;
        }
        //不支持宏，跳过
        else if (*i == '#')
        {
            while (*i != '\n')
            {
                i++;
            }
            i++;
            continue;
        }
        //空格跳过
        else if (*i == ' ' || *i == '\t')
        {
            i++;
            continue;
        }
        else if ((*i <= 'z' && *i >= 'a') || (*i <= 'Z' && *i >= 'A') || *i == '_')
        {
            string s;
            s += *i;
            i++;
            while ((*i >= 'a' && *i <= 'z') || (*i >= 'A' && *i <= 'Z') || (*i >= '0' && *i <= '9') || (*i == '_'))
            {
                s += *i;
                i++;
            }
            //符号查重
            bool Is_exited = false;
            for (auto i = symbol_table.begin(); i != symbol_table.end(); i++)
            {
                if (i->name == s)
                    Is_exited = true;
            }
            if (Is_exited)
            {
                cout << "variable " << s << endl;
                continue;
            }
            struct identifier id;
            id.token = Var;
            id.name = s;
            symbol_table.push_back(id);
            //输出
            cout << "variable " << s << endl;
        }
        //解析等号
        else if (*i == '=')
        {
            if (*(i + 1) == '=')
            {
                token = Eq;
                i += 2;
            }
            else
            {
                token = Assign;
                i++;
            }
        }
        //解析数字
        else if (*i <= '9' && *i >= '0')
        {
            token = Num;
            int val = *i - '0';
            i++;
            while (*i <= '9' && *i >= '0')
            {
                val = 10 * val + *i - '0';
                i++;
            }
            struct identifier id;
            id.token = Num;
            id.value = val;
            symbol_table.push_back(id);
        }
        //解析字符串
        else if (*i == '"')
        {
            string s;
            i++;
            while (*i != '"')
            {
                if (*(i - 1) == '\\' && *i == 'n')
                {
                    *(s.end() - 1) = '\n';
                    i++;
                }
                else
                {
                    s += *i;
                    i++;
                }
            }
            i++;
            cout << "识别字符串：" << s << endl;
            continue;
        }
        //小于和小于等于
        else if (*i == '<')
        {
            if (*(i + 1) == '=')
            {
                token = Le;
                i += 2;
            }
            else
            {
                token = Lt;
                i++;
            }
        }
        //大于和大于等于
        else if (*i == '>')
        {
            if (*(i + 1) == '=')
            {
                token = Ge;
                i += 2;
            }
            else
            {
                token = Gt;
                i++;
            }
        }
        //和与与
        else if (*i == '&')
        {
            if (*(i + 1) == '&')
            {
                token = Lan;
                i += 2;
            }
            else
            {
                token = And;
                i++;
            }
        }
        //条件或
        else if (*i == '|')
        {
            if (*(i + 1) == '|')
            {
                token = Lor;
                i += 2;
            }
            else
            {
                token = Or;
                i++;
            }
        }
        else if (*i == '[')
        {
            token = Brak;
            i++;
        }
        else if (*i == '%')
        {
            token = Mod;
            i++;
        }
        else if (*i == '!' && *(i + 1) == '=')
        {

            token = Ne;
            i += 2;
        }
        else if (*i == '*')
        {
            token = Mul;
            i++;
        }
        else if (*i == '+')
        {
            token = Add;
            i++;
        }
        else if (*i == '-')
        {
            token = Sub;
            i++;
        }
        else if (*i == '?')
        {
            token = Cond;
            i++;
        }
        else if (*i == '^')
        {
            token = Xor;
            i++;
        }
        else
        {
            //            token = Brak + 1;
            //            cout << *i << ' ';
            i++;
            continue;
        }
        cout << "token is: " << token << " : " << tk_type[token - 128] << " in line " << line << endl;
    }
    cout << "下面输出变量表" << endl;
    for (auto i = symbol_table.begin(); i != symbol_table.end(); i++)
    {
        int var = Var;
        if (i->token == var)
        {
            cout << "variable name " << i->name << endl;
        }
    }
    qDebug() << symbol_table.size() << "代码共有" << line << "行";
    return;
}
