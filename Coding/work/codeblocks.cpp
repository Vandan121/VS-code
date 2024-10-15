#include <bits/stdc++.h>
using namespace std;

// void Showall();

vector<pair<int, int> > Marks_Vector;
int SR_NO = 0;
int cnt = 0;

class Database
{
    vector<string> student_name;
    vector<int> sr_no;
    vector<int> physics;
    vector<int> chemistry;
    vector<int> maths;
    vector<int> total;
    vector<int> rank;

public:
    // constructor
    Database()
    {
        string temp;
        ofstream write;
        ifstream read1;

        write.open("Onlyone.dat");
        read1.open("NameData.dat");
        srand(time(0));
        int a,b,c1;
        while (read1 >> temp)
        {
            cnt++;
            a = ((rand() % 50) + 51);
            b = ((rand() % 50) + 51);
            c1 = ((rand() % 50) + 51);
            write << temp <<" ";
            write << a << " ";
            write << b << " ";
            write << c1 << " ";
            write << a+b+c1 << endl;
        }
        write.close();
        read1.close();
        // string str;

        ifstream read2;
        int p, c, m, i = 0,t;
        string name;
        read2.open("Onlyone.dat");

        while (read2 >> name >>p >> c >> m >>t )
        {
            sr_no.push_back(SR_NO);
            student_name.push_back(name);
            physics.push_back(p);
            chemistry.push_back(c);
            maths.push_back(m);
            

            // calculating the total marks
            total.push_back(t);
            Marks_Vector.push_back(make_pair(total[i], sr_no[i]));
            SR_NO++;
            i++;
        }
        read2.close();
    }

    void Show();
    void result()
    {
        sort(Marks_Vector.rbegin(), Marks_Vector.rend());

        cout << endl
             << "---------------------------------------" << endl
             << "              FINAL RESULT             " << endl
             << "---------------------------------------" << endl;

        for (int i = 0; i < cnt; i++)
        {
            cout << student_name[Marks_Vector[i].second] << " got the rank " << (sr_no[i] + 1) << " with ID " << Marks_Vector[i].second << " "<< total[Marks_Vector[i].second] <<endl;
        }
        cout << endl;
    }
};

void Database::Show()
{
    for (int i = 0; i < cnt; i++)
    {
        cout << endl;
        cout << "-------------------------------------------- " << endl
             << "Application number : " << sr_no[i] + 1 << endl
             << "Name : " << student_name[i] << endl
             << "Marks : " << endl
             << "P : " << physics[i] << endl
             << "C : " << chemistry[i] << endl
             << "M : " << maths[i] << endl
             << "Total : " << total[i] << endl
             << "-------------------------------------------- "
             << endl;
    }
    return;
}

int main()
{
    Database student;
    student.Show();
    student.result();

    return 0;
}
