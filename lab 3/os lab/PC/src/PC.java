
import java.util.Scanner;
import java.util.concurrent.Semaphore;
import java.util.logging.Level;
import java.util.logging.Logger;

class Q {

    // an item
    int item;
    int head = 0, tail = 0;
    int[] store = new int[100];

    static Semaphore emptyCount = new Semaphore(10 );
    static Semaphore fullcount = new Semaphore(0);
    static Semaphore mutex = new Semaphore(1);

    // to get an item from buffer
    void get(int CID) throws InterruptedException {
        System.out.println("Consumer C" + CID + " is trying to down the fullcount ");
        fullcount.acquire();
        mutex.acquire();
        item = store[head];
        head++;
        System.out.println("Consumer C" + CID + " is trying to increase the the Emptycount ");
        //emptyCount.release();
        System.out.println("Consumer  C" + CID + "Consumed item : " + item);
        mutex.release();
        emptyCount.release();

    }

    // to put an item in buffer
    void put(int item, int PID) throws InterruptedException {

        System.out.println("Producer P" + PID + " is trying to down the emptycount ");
        emptyCount.acquire();
        mutex.acquire();
        store[tail] = item;
        tail++;
        System.out.println("Producer P" + PID + " is trying to increase the the Fullcount ");
        //fullcount.release();
        System.out.println("Producer P" + PID + " put item : " + item);
        mutex.release();
        fullcount.release();

    }
}

// Producer class
class Producer implements Runnable {

    Q q;
    int PID;

    Producer(Q q, int PID) {
        this.q = q;
        this.PID = PID;

        new Thread(this, "Producer P" + this.PID).start();
    }

    public void run() {
        Scanner reader = new Scanner(System.in);  // Reading from System.in
        try {
            while (true) {

                System.out.println("Producer" + PID + ": Enter a number:  ");
                int n = reader.nextInt(); // Scans the next token of the input as an int.
//once finished

                q.put(n, PID);
            }

        } catch (InterruptedException ex) {
            Logger.getLogger(Producer.class.getName()).log(Level.SEVERE, null, ex);
        }

        reader.close();

    }
}

// Consumer class
class Consumer implements Runnable {

    int CID;
    Q q;

    Consumer(Q q, int CID) {
        this.q = q;
        this.CID = CID;
        new Thread(this, "Consumer C " + this.CID).start();
    }

    public void run() {
        try {
            while (true) {
                q.get(CID);
            }
        } catch (InterruptedException ex) {
            Logger.getLogger(Consumer.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}

// Driver class
class PC {

    public static void main(String args[]) {
        // creating buffer queue
        Q q = new Q();

        // starting consumer thread
        new Consumer(q, 0);
        new Consumer(q, 1);
        new Consumer(q, 2);

        new Producer(q, 0);
        new Producer(q, 1);
        // new Producer(q,2);
        //new Consumer(q);

        // starting producer thread
    }
}
