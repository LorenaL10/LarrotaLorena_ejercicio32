#include <iostream>
#include <fstream>
#include <cmath>
#include "stdio.h"

void init(double x);
void evolve(double x);

int main(){
    
    float rho=0.01;
    float ten =40.0;
    float c = sqrt(ten/rho);
    float cl =c;
    float radio =c*c/(cl*cl);
    float L=1.0;
    float t_max=0.1;
    float delta_x=1.0/100;
    float delta_t=0.001;
    float x=0.0;

    double m_vieja1[100];
    double m_vieja2[100];
    double m_nueva[100];
    
    
    double t=0.0;
    
    for (int i = 1; i<101; i++){
            m_vieja2[i]=pow(10, -4)*sin(2*3.14159*x/L);
    }
    
    for (int i = 1; i<100; i++){
        m_vieja1[i]=m_vieja2[i]+0.5*radio*(m_vieja2[i+1]+m_vieja2[i-1]-2*m_vieja2[i]);
        x+=delta_x;
    }
    
    while(t<t_max){
        for (int i = 1; i<100; i++){
        m_nueva[i]=2*m_vieja1[i]-m_vieja2[i]+radio*(m_vieja1[i+1]+m_vieja1[i-1]-2*m_vieja1[i]);
        std::cout << m_nueva[i]<< " ";     
    }
        for (int i = 1; i<101; i++){
            m_vieja2[i]=m_vieja1[i];
            m_vieja1[i]=m_nueva[i];
        }
        t+=delta_t;
    }
    
    
    return 0;
}




