#include <iostream>

class List {
    private:
        int *m_list;
        int m_length;
        int m_clength;

    public:
        List(int length = 10) : m_length(length), m_clength(0), m_list(new int[length])
        {
            std::cout << "List is created and initialized with 0s.\n";
            for (int i=0; i<m_length; ++i) {
                *(m_list + i) = 0;
            }
        }
        
        bool push(int num) {
            if (m_clength == m_length) {
                std::cout << "Cannot push(). List is full.\n";
                return false;
            } else {
                m_clength++;
                *(m_list + m_clength - 1) = num;
                return true;
            }
        }

        bool unshift(int num) {
            if (m_clength == m_length) {
                std::cout << "Cannot unshift(). List is full.\n";
                return false;
            } else {
                m_clength++;
                for (int i=m_clength-1; i>=0; --i) {
                    for (int k=i-1; k>=0; --k) {
                        *(m_list + i) = *(m_list + k);
                        break;
                    }
                }
                *m_list = num;
                return true;
            }
        } 

        bool shift() {
            if (m_clength == 0) {
                std::cout << "Cannot shift(). List is empty.\n";
                return false;
            } else {
                *m_list = 0;
                for (int i=0; i<m_clength; ++i) {
                    for (int k=i+1; k<m_clength; ++i) {
                        *(m_list + i) = *(m_list + k);
                        break;
                    }
                }
                m_clength--;
                return true;
            }
        }

        void pop() {
            if (m_clength == 0) {
                std::cout << "Pop() is meaningless. List is empty.\n";
            } else {
                *(m_list + m_clength - 1) = 0;
                m_clength--;
            }
        }

        void print() {
            for (int i=0; i<m_clength; ++i) {
                std::cout << *(m_list + i) << " ";
            }
            std::cout << '\n';
        }

        ~List() {
            delete[] m_list;
        }
};

int main() {
    using namespace std;

    List list;

    list.push(1);
    list.push(2);
    list.push(3);
    list.print();

    list.pop();
    list.print();

    list.shift();
    list.print();

    list.unshift(666);
    list.print();

    return 0;
}
