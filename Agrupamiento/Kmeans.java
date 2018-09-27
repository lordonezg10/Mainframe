import java.io.*;

class Punto{
    int x;;
    int y;
    
    Punto(int x, int y){
        this.x = x;
        this.y = y;
    }

    public int getX() {
        return x;
    }

    public void setX(int x) {
        this.x = x;
    }

    public int getY() {
        return y;
    }

    public void setY(int y) {
        this.y = y;
    }
    
    
}

public class Kmeans {
    
    int []x = {14,15,14,16,18,20};
    int []y = {28,29,30,35,28,43};
    int []v = new int[x.length];
    Punto p1, p2;
    
    public Kmeans(){
        p1 = new Punto(0,0);
        p2 = new Punto(50,50);
    }
    
    public void CalcularDistancias(){
        double d1, d2;
        for(int i=0; i < x.length; i++){
            d1 = Math.sqrt( Math.pow(x[i]-p1.getX(),2) + Math.pow(y[i]-p1.getY(),2) );
            d2 = Math.sqrt( Math.pow(x[i]-p2.getX(),2) + Math.pow(y[i]-p2.getY(),2) );
            
            if(d1 <= d2) v[i] = 1;
            else v[i] = 2;
        }
    }
    
    public void ActualizarPuntos(){
        double sX1 = 0, sY1 = 0, sX2 = 0, sY2 = 0;
        int c1 = 0, c2 = 0;
        for(int i = 0; i < x.length; i++){
            if(v[i] == 1){
                sX1 += Math.abs(x[i]);
                sY1 += Math.abs(y[i]);
                c1++;
            }else{
                sX2 += Math.abs(x[i]);
                sY2 += Math.abs(y[i]);
                c2++;
            }
        }
        p1.setX((int)(sX1/c1));
        p1.setY((int)(sY1/c1));
        p2.setX((int)(sX2/c2));
        p2.setY((int)(sY2/c2));   
    }
    
    public void Visualizar(){
        System.out.println("P1: X = " + p1.getX() + ", Y = " + p1.getY());
        System.out.println("P2: X = " + p2.getX() + ", Y = " + p2.getY());
    }
    
    public static void main(String[] args) throws IOException{
        Kmeans obj = new Kmeans();
        for(int i = 1; i == i; i++){
          	System.out.println("Iteracion "+ i);
          	obj.Visualizar();
            int x1 = obj.p1.getX();
            int y1 = obj.p1.getY();
            int x2 = obj.p2.getX();
            int y2 = obj.p2.getY();
            obj.CalcularDistancias();
            obj.ActualizarPuntos();
            if(x1 == obj.p1.getX() && y1 == obj.p1.getY() && x2 == obj.p2.getX() && y2 == obj.p2.getY()){
                break;
            }
        }
    } 
}
