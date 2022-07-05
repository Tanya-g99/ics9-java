public class Series {
    private double a1, d;

    public Series(double varA1, double varD){
        this.a1 = varA1;
        this.d = varD;
    }

    public void belongNumber(double c){
        if ((c - this.a1)%this.d == 0) 
            System.out.println("Число " + c + " является членом этой арифметической прогрессии");
        else System.out.println("Число " + c + " не является членом этой арифметической прогрессии");
    }

    public double sum(int n){
        return ((this.a1 * 2 + this.d * (n - 1))/2)*n;
    }

    public String toString(){
        return "Арифметическая прогрессия с a1 = " + this.a1 + " и d = "+this.d;
    }
}
