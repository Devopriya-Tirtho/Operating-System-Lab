/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package online4;

import java.util.ArrayList;
import java.util.Scanner;
import java.util.concurrent.Semaphore;



public class Online4 {
    static Semaphore readlock =new Semaphore(1);
    static Semaphore writelock = new Semaphore(1);
    static int readCount =0;
    static int ido =0;
   static int[] ints = {1, 2, 3};
    static ArrayList<Integer> buffer = new ArrayList<>();

    static class Read implements Runnable
        {
        @Override
        
        public void run() {
            try {
                //Acquire Section
                readlock.acquire();
                //readCount++;
               
                readCount++;
                
                if (readCount == 1) {
                    writelock.acquire();
                }
                readlock.release();
                ido++;
                System.out.println("Thread "+Thread.currentThread().getName() + " is READING the value " +buffer.get(ido) );
                Thread.sleep(1500);
                System.out.println("Thread "+Thread.currentThread().getName() + " has FINISHED READING");

                readlock.acquire();
     
                 readCount--;
                
                if(readCount == 0) {
                    writelock.release();
                }
                
                readlock.release();
            } catch (InterruptedException e) {
                System.out.println(e.getMessage());
            }
        }
    }

    static class Write implements Runnable {
        @Override
        public void run() {
            try {
                writelock.acquire();
                System.out.println("Thread "+Thread.currentThread().getName() + " is WRITING");
                Scanner scanner = new Scanner(System.in);
                int n= scanner.nextInt();
                buffer.add(n);               
                Thread.sleep(1000);           
                 System.out.println("the new set of data is ");
                 
                
                System.out.println("Thread "+Thread.currentThread().getName() + " has finished WRITING");
                for (int i=0; i< buffer.size(); i++) {
                    System.out.print( buffer.get(i)+" "); 
                    
                 } 
               System.out.println("");
                writelock.release();
            } catch (InterruptedException e) {
                    
                System.out.println(e.getMessage());
            }
        }
    }

    public static void main(String[] args) throws Exception {

        Read read = new Read();
        Write write = new Write();
        Thread t1 = new Thread(read);
        t1.setName("thread1");
        Thread t2 = new Thread(read);
        t2.setName("thread2");
        Thread t3 = new Thread(write);
        t3.setName("thread3");
        Thread t4 = new Thread(write);
        t4.setName("thread4");
        t1.start();
        t3.start();
        t2.start();
        t4.start();
           for (int i : ints)
    {
        buffer.add(i);
    }
        
    }
    
}
