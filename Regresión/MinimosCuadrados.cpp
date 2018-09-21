#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
#define longitud 11

class Regresion {
	private:
		double* x;
		double* y;
		double* xy;
		double* x2;
		double* y2;	
		double sx;		
		double sy;
		double sxy;
		double sx2;
		double sy2;
		double promx;
		double promy;
		double cantX;
		double cantY;
		double cantXY;
		double pendiente;
		double corteY;
	
	public:
		Regresion() {
			double tx[] = { 14,7,13,12,16,14,18,13,12,16,13 };
			double ty[] = { 16,12,13,14,15,12,16,11,13,18,17 };
			x = tx;
			y = ty;
			xy = new double[longitud];
			x2 = new double [longitud];
			y2 = new double [longitud];			
			sx = 0, sy = 0, sxy = 0, sx2 = 0, sy2 = 0; 
			//leerArchivo();
			calcularMatriz();
			calcularPromedio();
			calcularCantidades();
			calcularPendiente();
			calcularCorteY();
		}
		/*void leerArchivo() {
			ifstream arch("datos.csv");
			string registro, cadena;
			short c = 0;
			x = new double[longitud];
			y = new double[longitud];
			while (getline(arch, registro)){
				stringstream ss(registro);
				getline(ss, cadena, ',');
				x[c] = atof(cadena.c_str());
				//cout << cadena << endl;
				getline(ss, cadena);
				y[c] = atof(cadena.c_str());
				c++;
				//cout << cadena << endl;
			}
		}*/
		void calcularMatriz() {
		
			for (int i = 0; i < longitud; ++i) {
				xy[i] = x[i] * y[i];
				x2[i] = pow(x[i], 2);
				y2[i] = pow(y[i], 2);
				
			}
			for (int i = 0; i < longitud; ++i) {
				sx = sx + x[i];
				sy = sy + y[i];
				sxy = sxy + xy[i];			
				sx2 = sx2 + x2[i];
				sy2 = sy2 + y2[i];
			}
		}
		void calcularPromedio() {
			promx = sx / longitud;
			promy = sy / longitud;
		}
		void calcularCantidades(){
		    cantX = sizeof(x);
		    cantY = sizeof(y);
		    cantXY = cantX + cantY;
		}
		void calcularPendiente()
		{
		  pendiente = (sxy - ((sx * sy)/cantXY))/(sx2 - ((sx)/cantXY));
		}
		
		void calcularCorteY(){
			corteY = promy - pendiente*promx;
		}
	
		void visualizar() {
			cout << "La Cantidad de X es  : " << cantX << endl;
			cout << "La Cantidad de Y es  : " << cantY << endl;
			cout << "La Cantidad de X + Y es  : " << cantXY << endl;
			cout << "La Pendiete es  : " << pendiente << endl;
			cout << "Corte de Y con la recta es : : " << corteY << endl;
		}
		
		
};

int main() {
	Regresion r;
	r.visualizar();
	cin.get();
}
