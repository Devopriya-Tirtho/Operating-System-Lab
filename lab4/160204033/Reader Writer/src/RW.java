
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.concurrent.Semaphore;

public class RW {

    static Scanner sc = new Scanner(System.in);
    static Semaphore ReadLock = new Semaphore(1);
    static Semaphore WriteLock = new Semaphore(1);
    static int readCount = 0;
    static List l = new ArrayList(Arrays.asList(1, 5, 6, 7, 8, 9, 15));

    static class Write implements Runnable {

        public void run() {
            try {
                WriteLock.acquire();
                System.out.println("Writer " + Thread.currentThread().getName() + ": Writing ");
                System.out.print("Enter a Value: ");
                l.add(sc.nextInt());
                Thread.sleep(1500);
                System.out.println("Writer " + Thread.currentThread().getName() + ": Leaves");
                System.out.print("Values are: ");
                for (int i = 0; i < l.size(); i++) {
                    System.out.print(l.get(i) + " ");
                }
                System.out.println();
                WriteLock.release();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    static class Read implements Runnable {

        public void run() {
            try {
                ReadLock.acquire();
                readCount++;
                if (readCount == 1) {
                    WriteLock.acquire();
                }
                ReadLock.release();

                int num = (int) l.get(0);
                l.remove(new Integer(num));
                Thread.sleep(2500);
                System.out.println("Reader " + Thread.currentThread().getName() + ": Reading " + num);
                System.out.println("Reader " + Thread.currentThread().getName() + ": Finished Reading ");
                ReadLock.acquire();
                readCount--;
                if (readCount == 0) {
                    WriteLock.release();
                }
                ReadLock.release();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public static void main(String[] args) {
        Read r = new Read();
        Write w = new Write();
        Thread t1 = new Thread(r);
        Thread t2 = new Thread(w);
        Thread t3 = new Thread(r);
        Thread t4 = new Thread(w);

        t1.setName("1");
        t2.setName("1");
        t3.setName("2");
        t4.setName("2");
        System.out.print("Values are: ");
        for (int i = 0; i < l.size(); i++) {
            System.out.print(l.get(i) + " ");
        }
        System.out.println();
        t1.start();
        t2.start();
        t3.start();
        t4.start();

    }
}
