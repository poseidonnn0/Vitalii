#include <iostream>
#include <BinaryTree.hpp>

int main()
{
		Tree::Elem* root = nullptr;
        int N = 20;
        srand(time(0));
        for (int i = 0; i < N; i++)
        {
            int a = i * rand() % 100;
            Tree::ADD(a, root);
        }
		Tree::PASS(root);

        std::cout << "\nCenter: "; // центральный обход
        Tree::center(root);
        std::cout << "\nByPass: "; // прямой обход
        Tree::bypass(root);
        std::cout << "\nEndByPass: "; // концевой обход
        Tree::EndBypass(root);
        std::cout << "\n\n\n";
        Tree::CLEAR(root);
		return 0;
}