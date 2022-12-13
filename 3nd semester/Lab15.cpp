#include <iostream>
#include<string>
#include <vector>
class Tree
{
public:
	int value;
	Tree* parent;
	Tree* left;
	Tree* right;
	std::string string; // для линейно-скобочной записи.
    Tree(const int v, Tree* p)
    {
        value = v;
        parent = p;
    }

    Tree()
    {

    }

    Tree(std::string str)
    {
        string = str;
    }

    void add(const int v)
    {
        if (v > value)
        {
            if (right == nullptr)
            {
                right = new Tree(v, this);
            }
            else
            {
                right->add(v);
            }
        }
        else
        {
            if (left == nullptr)
            {
                left = new Tree(v, this);
            }
            else
            {
                left->add(v);
            }
        }
    }


    std::string toString(int value) // переводит число в строку
    {
        std::string result;

        if (value > 9)
        {
            result += char(value / 10 + 48);
            result += char(value % 10 + 48);
        }
        else
        {
            result += char(value + 48);
        }

        return result;
    }


    void print(Tree* tree) // переводит дерево в линейно-скобочуню запись
    {
        string += toString(tree->value);
        if (tree->left != nullptr || tree->right != nullptr)
        {
            string += '(';
            if (tree->left != nullptr)
            {
                print(tree->left);
            }
            string += ',';
            if (tree->right != nullptr)
            {
                print(tree->right);
            }
            string += ')';
        }

    }
    
    
    void Print()
    {
        print(this);
    }


    bool isDigital(const char elem)
    {
        return (elem >= '0' && elem <= '9') ? true : false;
    }


    Tree parse(std::string str) // парсит  строку в бинарное дерево
    {
        Tree result;
        int index;
        if (isDigital(str[0]) && isDigital(str[1]))
        {
            int val = (str[0] - 48) * 10 + str[1] - 48;
            result.value = val;
            index = 2;
        }
        else if (isDigital(str[0]) && !isDigital(str[1]))
        {
            int val = str[0] - 48;
            result.value = val;
            index = 1;
        }


        for (int i = index; i < str.size() - 1;)
        {
            if (isDigital(str[i]) && isDigital(str[i + 1]))
            {
                int value = (str[i] - 48) * 10 + str[i + 1] - 48;
                result.add(value);
                i += 2;
            }
            else if (isDigital(str[i]) && !isDigital(str[i + 1]))
            {
                int value = str[i] - 48;
                result.add(value);
                i++;
            }
            else
            {
                i++;
            }
        }

        return result;
    }
};


void direct(std::vector <int>& v, const Tree* tree)
{
    if (tree != nullptr)
    {
        v.push_back(tree->value);
        direct(v, tree->left);
        direct(v, tree->right);
    }    
}

void center(std::vector<int>& v, const Tree* tree)
{
    if (tree != nullptr)
    {
        center(v, tree->left);
        v.push_back(tree->value);
        center(v, tree->right);
    }
}

void reverse(std::vector<int>& v, const Tree* tree)
{
    if (tree != nullptr)
    {
        reverse(v, tree->left);       
        reverse(v, tree->right);
        v.push_back(tree->value);
    }
}


void main()
{
    std::vector <int> directValues;
    std::vector <int> centerValues;
    std::vector <int> reverseValues;
	int maxElem;
    std::string str = "8(3(1,6(4,7)),10(,14(13,)))";
    Tree tree;
    tree = tree.parse(str);
    Tree newTree = tree;
    newTree.Print();

    direct(directValues, &newTree); //прямой обход
    center(centerValues, &newTree); //кольцевой обход
    reverse(reverseValues, &newTree); //обратный обход

    for (auto& value : reverseValues)
    {
        std::cout << value<<"\t";
    }
}