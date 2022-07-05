public class Universe {
    public static void main(String[] args) {
        Particle A = new Particle(10, 10);
        A.data();
        A.n();
        A.e();

        Particle B = new Particle(50, 100);
        B.data();
        B.n();
        B.e();

        Particle C = new Particle(1, 100);
        C.data();
        C.n();
        C.e();
    }
}
