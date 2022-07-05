public class Particle {
    private static int n = 0;
    private static double e = 0;
    private double m, v;

    public Particle(double inM, double inV){
        this.m = inM;
        this.v = inV;
        Particle.n += 1;
        Particle.e += m * v * v / 2;
    }

    public void n(){
        System.out.println("Количество частиц: " + Particle.n);
    }

    public void e(){
        System.out.println("Суммарная кинетическая энергия частиц: " + Particle.e);
    }

    public void data(){
        System.out.println("масса = " + this.m + ", скорость = " + this.v);
    }
}
