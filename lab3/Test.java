import java.util.Arrays;
public class Test {
    public static void main(String[] args) {
        Sequencing[] A = new Sequencing[] {
            new Sequencing(1,2,3,4),
            new Sequencing(9, 100),
            new Sequencing(9, 100, 1, -4),
            new Sequencing(9, -3, -10),
            new Sequencing(-43, -3, -2, -1, 0, 0)
        };
        System.out.println("До сортировки:");
        for (Sequencing s : A) System.out.println(s);
        Arrays.sort(A);
        System.out.println("После: ");
        for (Sequencing s : A) System.out.println(s);
    }
}
