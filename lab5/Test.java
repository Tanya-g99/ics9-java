public class Test {
    public static void main(String[] args) {
        Matrix test = new Matrix(5, 4);
        test.setElem(2, 4, 1);
        test.setElem(0, 1, 1);
        test.setElem(2, 2, 1);
        test.setElem(2, 3, 1);
        test.setElem(3, 1, 1);
        //System.out.println(test.getX());
        System.out.println(test.getElem(0, 1));
        System.out.println(test.getElem(0, 3));
        System.out.println("Количество нулевых строк: " + test.countZero());
        System.out.println("Количество ненулевых строк: " + (test.getM() - test.countZero()));
        System.out.println(test.getString().get());
        //System.out.println("Результат ввода индекса, превышающего размеры матрицы(Исключение):");
        //test.setElem(7, 1, 1);
        //System.out.println("Результат ввода элемента, значение которого не удовлетворяет значениям булевской марицы(Исключение):");
        //test.setElem(2, 1, 3);
    }
}
