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

        std::cout << "\nStackByPass: "; 
        Tree::StackByPass(root); //Не рекурсивный прямой обход(стек)
        std::cout << "\n\n\n";
        Tree::CLEAR(root);
		return 0;
}