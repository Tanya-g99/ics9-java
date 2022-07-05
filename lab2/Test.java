public class Test {
    public static void main(String[] args) {
        Series A = new Series(3, 2);
        System.out.println(A.toString());
        A.belongNumber(7);
        A.belongNumber(10);
        System.out.println("Сумма: " + A.sum(20));

        Series B = new Series(32, -15);
        System.out.println(B.toString());
        B.belongNumber(-28);
        B.belongNumber(4);
        System.out.println("Сумма: " + B.sum(9));
        }
}
