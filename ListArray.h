#include <ostream>
#include "List.h"
#include <iostream>

using namespace std;

template <typename T>

class ListArray: public List<T>
{
    private:
        T* arr;
        int max, n;
        static const int MINSIZE=2;
        void resize(int new_size)
        {
            int i;
            T* aux = new int [new_size];
            for(i=0; i<size(); i++)
            {
                aux[i]=arr[i];
            }
            delete [] arr;
            arr=aux;
            max=new_size;
        }

    public:
        //METODOS DE LISTARRAY
        ListArray()
        {
            max=0;
            arr=new int[0];
            n=0;
        }

        ~ListArray()
        {
            delete arr;
        }

        T operator[](int pos)
        {
            if (pos<0|| pos>size()-1)
                throw std::out_of_range("Posicion no valida.\n");
            return arr[pos];
        }

        friend ostream& operator<<(ostream &out, const Listarray<T> &list)
        {
            int i;
            out << "List ->[";
            if (0<list.max)
                out<<endl;
            for (i=0; i<list.max; i++)
            {
                out << " " <<list.arr[i];
            }
            out << "]";
            return out;
        }

        //METODOS DE CLASE LIST
        void insert (int pos, T e) override
        {
            int i;
            if (pos<0 || pos>size())
                throw out_of_range("Posicion no valida.\n");
            n++
            resize(n);
            if (pos<n)
            {
                for (i=0; i<n-pos; i++)
                {
                    arr[n-1]=arr[n-1-i];
                }
            }
            arr[pos]=e;
        }

        void append(T e) override
        {
            n++;
            resize(n);
            arr[size()-1]=e;
        }

        void prepend(T e) override
        {
            int i;
            n++;
            resize(n);
            for(i=0; i<size(); i++)
            {
                arr[size()-1-i]=arr[size()-2-i];
            }
            arr[0]=e;
        }

        T remove (int pos) override
        {
            int aux, i;
            if (pos<0 || pos>size()-1)
                throw out_of_range("Posicion no valida.\n");
            aux=arr[pos];
            if (pos<n)
            {
                for (i=pos; i<n; i++)
                {
                    arr[i]=arr[i+1];
                }

            }
            n--;
            resize(n);
            return aux;
        }

        T get (int pos) override
        {
            if (pos<0 || pos>size()-1)
                throw out_of_range("Posicion no valida.\n");
            return arr[pos];
        }

        int search(T e) override
        {
            int pos;
            for (pos=0; pos<size(); pos++)
            {
                if (arr[pos]==e)
                    return pos;
            }
            return -1;
        }

        bool empty() override
        {
            if(n>0)
                return false;
            else
                return true;
        }

        int size() override
        {
            return n;
        }

	void duplicate_list() override
	{
	    int i, m, x;
	    resize(n*2);
	    m=max/2;
	    x=m+1;
    	    if ((m/2)%2!=0)
		printf("Tamanyo inadecuado. Debe ser un numero par para realizar esta funcion.\n");
	    else
	    {
		for (i=0; i<m; i++)
		{
		    arr[x]=arr[i];
		    x++;
		}
	    }	    
	}
};
