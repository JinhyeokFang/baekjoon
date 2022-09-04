#include <iostream>
#include <vector>

using namespace std;

string calculate(string);
string merge(vector<string>);

vector<string> step1(string formula)
{
    vector<string> result;
    bool is_calculating_inner_formula = false;
    int count = 0;
    int start_index_inner_formula, end_index_inner_formula;
    for (int i=0; i<formula.size(); i++)
    {
        if (!is_calculating_inner_formula && formula[i] != '(')
            result.push_back(formula.substr(i, 1));
        if (formula[i] == '(')
        {
            if (!is_calculating_inner_formula)
            {
                is_calculating_inner_formula = true;
                start_index_inner_formula = i + 1;
            }
            count++;
        }
        if (formula[i] == ')')
        {
            count--;
            if (count == 0)
            {
                is_calculating_inner_formula = false;
                end_index_inner_formula = i - 1;
                result.push_back(
                    calculate(
                        formula.substr(
                            start_index_inner_formula, 
                            end_index_inner_formula - start_index_inner_formula + 1
                        )
                    )
                );
            }
        }
        // cout << '[' << merge(result) << ']' << '\n';
    }
    return result;
}
vector<string> step2(vector<string> formula)
{
    for (int i=0; i<formula.size(); i++)
    {
        if (formula[i] == "*" || formula[i] == "/")
        {
            formula[i - 1] = formula[i - 1] + formula[i + 1] + formula[i];
            formula.erase(formula.begin() + i);
            formula.erase(formula.begin() + i);
            i = 0;
        }
    }
    return formula;
}
vector<string> step3(vector<string> formula)
{
    for (int i=0; i<formula.size(); i++)
    {
        if (formula[i] == "+" || formula[i] == "-")
        {
            formula[i - 1] = formula[i - 1] + formula[i + 1] + formula[i];
            formula.erase(formula.begin() + i);
            formula.erase(formula.begin() + i);
            i = 0;
        }
    }
    return formula;
}
string merge(vector<string> formula)
{
    string result = "";
    for (int i=0; i<formula.size(); i++)
        result += formula[i];
    return result;
}

string calculate(string formula)
{
    if (formula.length() == 1)
        return formula;
    vector<string> one = step1(formula);
    // cout << "one " << merge(one) << '\n';
    vector<string> two = step2(one);
    // cout << "two " << merge(two) << '\n';
    vector<string> three = step3(two);
    // cout << "three " << merge(three) << '\n';
    return merge(three);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    cout << calculate(s);
}
