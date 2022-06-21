package com.company;

import java.util.Random;
import java.lang.Exception;

public class Producer extends java.lang.Thread {
    //Necessary variables and object declaration
    Random randomWithSeed;
    int count;
    int prodNum;
    int index = 0;
    public int checkSum = 0;
    int id;
    int seed;
    int producedItem;
    final Buffer shareBuffer;


    public Producer(Buffer buff, int count, int id, int seed) {
        //Assign values to the variables
        this.randomWithSeed = new Random(seed);
        this.id = id;
        this.count = count;
        this.seed = seed;
        this.shareBuffer = buff;
    }



    //EACH PRODUCER THREAD TERMINATES WHEN THE SPECIFIED NUMBER OF ITEMS HAS BEEN PRODUCED

    @Override
    public void run() {

        while (prodNum != count) {
            synchronized (shareBuffer) {
                while (shareBuffer.isFull()) {
                    try {
                        shareBuffer.wait();
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }

//                try {

                int variable = randomWithSeed.nextInt(100);
                // *** Critical Section ***
                int producedItem = shareBuffer.insert(variable);
                checkSum += producedItem;
                prodNum++;
                System.out.println("Producer " + this.id + " inserted " + producedItem + "  " + "at index " + shareBuffer.prodindex + " at time " + Coordinator.getTime());
                index++;
                // Exit Section
                shareBuffer.notify();
            }

/*
                } catch (IllegalStateException e) {
                    e.printStackTrace();
                }
*/

            }
        }


    public int getCheckSum()
    {
        return this.checkSum;
    }
}





