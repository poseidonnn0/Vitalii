#include <iostream>
#include <fstream>
#include <iostream>

int main() {
    const int s = 4;
    char mas_1[s];
    int count = 0;
    int k = 0, parity = 0;
    char N;
    std::ifstream fin("input.txt");
    std::ofstream fout_1("A.txt");
    std::ofstream fout_2("B.txt");
    std::ofstream fout_3("C.txt");
    std::ofstream fout_4("D.txt");

    std::ifstream fin_1("A.txt");
    std::ifstream fin_2("B.txt");
    std::ifstream fin_3("C.txt");
    std::ifstream fin_4("D.txt");

    std::ofstream out_exit("Exit.txt");

    if (fin.is_open())
    {
        while (!fin.eof()) 
        {
            if (count < 4) 
            {
                k = 0;
                while (k < s)
                {
                    fin >> N;
                    mas_1[k] = N;
                    k++;
                }
                for (int i = 0; i < s; i++) 
                {
                    for (int j = i + 1; j < s; j++) 
                    {
                        if (mas_1[i] > mas_1[j]) 
                        {
                            char tmp;
                            tmp = mas_1[i];
                            mas_1[i] = mas_1[j];
                            mas_1[j] = tmp;
                        }
                    }
                }
                if (parity % 2 == 0) 
                {
                    for (int i = 0; i < s; i++) 
                    {
                        fout_1 << mas_1[i];
                    }
                }
                else 
                {
                    for (int i = 0; i < s; i++) 
                    {
                        fout_2 << mas_1[i];
                    }
                }
                parity++;
                count++;
            }
            else
            {
                break;
            }
        }
    }

    fin.close();
    fout_1.close();
    fout_2.close();

    k = 0;

    char mas[s];
    char mas_2[s];
    int count_1 = 0;

    while (!fin_1.eof() && !fin_2.eof()) 
    {
        if (count_1 < 2) 
        {
            k = 0;
            while (k < s)
            {
                fin_1 >> N;
                mas[k++] = N;
            }
            k = 0;
            while (k < s)
            {
                fin_2 >> N;
                mas_2[k++] = N;
            }

            int u = 0, t = 0;
            int l = 0;

            if (count_1 % 4 == 0 || count_1 % 4 == 2) 
            {
                while (l < 2 * s) 
                {
                    if (u < s && t < s) 
                    {
                        if (mas[u] > mas_2[t]) 
                        {
                            fout_3 << mas_2[t];
                            t++;
                        }
                        else 
                        {
                            fout_3 << mas[u];
                            u++;
                        }
                    }
                    else 
                    {
                        if (u < s) 
                        {
                            fout_3 << mas[u];
                            u++;
                        }
                        else if (t < s) 
                        {
                            fout_3 << mas_2[t];
                            t++;
                        }
                    }
                    l++;
                }
            }
            else if (count_1 % 4 == 1 || count_1 % 4 == 3) 
            {
                while (l < 2 * s) 
                {
                    if (u < s && t < s) 
                    {
                        if (mas[u] > mas_2[t]) 
                        {
                            fout_4 << mas_2[t];
                            t++;
                        }
                        else 
                        {
                            fout_4 << mas[u];
                            u++;
                        }
                    }
                    else 
                    {
                        if (u < s) 
                        {
                            fout_4 << mas[u];
                            u++;
                        }
                        else if (t < s) 
                        {
                            fout_4 << mas_2[t];
                            t++;
                        }
                    }
                    l++;
                }
            }
            count_1++;
        }
        else
        {
            break;
        }
    }
    fout_3.close();
    fout_4.close();
    int p = 0;
    char mas_i[2 * s];
    char ma[2 * s];

    while (!fin_4.eof() && !fin_3.eof()) 
    {
        if (p < 1) 
        {
            k = 0;
            while (k < 2 * s)
            {
                fin_3 >> N;
                mas_i[k++] = N;
            }
            k = 0;
            while (k < 2 * s)
            {
                fin_4 >> N;
                ma[k++] = N;
            }
            int u = 0, t = 0;
            int l = 0;
            while (l < 4 * s) 
            {
                if (u < 2 * s && t < 2 * s) 
                {
                    if (mas_i[u] > ma[t]) 
                    {
                        out_exit << ma[t] << " ";
                        t++;
                    }
                    else 
                    {
                        out_exit << mas_i[u] << " ";
                        u++;
                    }
                }
                else 
                {
                    if (u < 2 * s) 
                    {
                        out_exit << mas_i[u] << " ";
                        u++;
                    }
                    else if (t < 2 * s) 
                    {
                        out_exit << ma[t] << " ";
                        t++;
                    }
                }
                l++;
            }
        }
        else
        {
            break;
        }
        p++;
    }
    fin_1.close();
    fin_2.close();
    fin_3.close();
    fin_4.close();
}