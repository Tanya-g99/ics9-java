import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Optional;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.util.stream.Stream;

public class Matrix {
    private int m, n;
    private long x;
    private int[] rowSums;

    public String getX() {
        return Long.toBinaryString(x);
    }

    public Matrix(int m, int n){
        this.m = m;
        this.n = n;
        x = 0;
        rowSums = new int[m];
    }

    public int getM() {
        return m;
    }

    public long getElem(int i, int j){
        try {
            if (i >= n || j >= m){
                throw new IndexOutOfBoundsException();
            }
            return  (x&1<<(i*n+j))>>(i*n+j);
        } catch (Exception e) {
            System.out.println(e);
            return -1;
        }
    }

    public void setElem(int i, int j, int elem){
        try {
            if (i >= n || j >= m){ throw new IndexOutOfBoundsException();}
            if (elem!=1 && elem!=0){throw new IllegalArgumentException("the argument entered is not 1 or 0");}

            if (elem == 1 && getElem(i, j) == 0) {
                rowSums[i] += 1;
            }
            if (elem == 0 && getElem(i, j) == 1) {
                rowSums[i] -= 1;
            }
            x |= (elem<<(i*n+j));
            
        } catch (Exception e) {
            System.out.println("\u001B[31m" + e + "\u001B[0m");
        }
    }

    public ArrayList<Integer> arrayStream(){
        return new ArrayList<>(Arrays.stream(rowSums).boxed().collect(Collectors.toList()));
    }
    public Stream<Integer> sumStream(){
        ArrayList<Integer> result = new ArrayList<>();
        ArrayList<Integer> temp = arrayStream();
        temp.stream().forEach(x -> result.add(x % 2));
        return result.stream();
    }

    public Optional<Integer> getString(){
        Optional<Integer> result = Optional.empty();
        ArrayList<Integer> temp = arrayStream();
        Optional<Integer> temp2 =  IntStream.range(0, temp.size()).boxed().max(Comparator.comparing(temp::get));
        if (temp2.isPresent()){
            result = Optional.ofNullable(temp2.get());
        }
        return result;
    }

    public int countZero(){
        return (int)arrayStream().stream().filter(x -> x == 0).count();
    }

}
