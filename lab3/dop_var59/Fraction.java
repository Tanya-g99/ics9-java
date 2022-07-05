public class Fraction implements Comparable<Fraction>{
    private int a, b;
    public Fraction(int inA, int inB){
        this.a = inA;
        this.b = inB;
    }

    public double rational(){ 
        return (double)a / b;
    }

    public int compareTo(Fraction obj) {
        if (rational() < obj.rational()) return -1;
        if (rational() == obj.rational()) return 0;
        return 1;
    }

    public String toString(){
        return a + "/" + b + " = " + rational();
    }
}
