public class Particle //4var
{
    private static int n = 0;
    private static double e = 0;
    private double m, v;

    public Particle(double inM, double inV){
        this.m = inM;
        this.v = inV;
        Particle.e = (Particle.e * n + m * v * v / 2) / (Particle.n + 1);
        Particle.n += 1;
    }

    public void n(){
        System.out.println("Количество частиц: " + Particle.n);
    }

    public void e(){
        System.out.println("Средняя кинетическая энергия частиц: " + Particle.e);
    }

    public void data(){
        System.out.println("масса = " + this.m + ", скорость = " + this.v);
    }
}
