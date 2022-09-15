#include "Array.h"

Array::Array()
{
    datos = 3;
}

void Array::Leer()
{
    Init();
    cout<<"\t..... LECTURA DE DATOS ....."<<endl;
    for(int i = 0; i<n_empleados; ++i)
    {
        cout<<"Nombre: ";
        cin>>*(*(empleado)+i);
        cout<<"Antiguedad: ";
        cin>>*(*(empleado+1)+i);
        cout<<"Piezas Fabricadas: ";
        cin>>*(*(empleado+2)+i);
    }
}

void Array::Mostrar()
{
    cout<<"\t\t..... MOSTRAR DATOS .....\n"<<endl;
    cout<<"Empleado\t Antiguedad\t Piezas \tNombre"<<endl;
    for(int i = 0; i<n_empleados; ++i)
    {
        cout<<"\n"<<i+1<<" ... ";
        cout<<"     ";
        for(int j=datos; j>0; j=j-1)
        {
            cout<<*(*(empleado+j-1)+i)<<"    \t\t";
        }
        cout<<endl;
    }
    cout<<endl;
}

void Array::Init()
{
    cout<<"Cuantos empleados de la fabrica quiere registrar?: ";
    cin>>n_empleados;

    empleado = new string*[datos];
    for (int i = 0; i< datos; ++i)
    {
        *(empleado + i) = new string[n_empleados];
    }
}

void Array::Ordenar()
{
    string com;
    for (int i=0; i<n_empleados; ++i)
    {
        for(int j=0; j<n_empleados-1; ++j)
        {   
            if(*(*(empleado+2)+j)>*(*(empleado+2)+j+1))
            {
                for (int k = 0; i < n_empleados; k++)
                {
                    com = *(*(empleado+k)+j);
                    *(*(empleado+k)+j)= *(*(empleado+k)+j+1);
                    *(*(empleado+k)+j+1) = com;
                }
            }
        }
    }
    Mostrar();
}
