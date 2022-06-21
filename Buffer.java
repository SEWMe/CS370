package com.company;

import java.util.Arrays;

public class Buffer {

    //FIXEDSIZE NEEDS TO CHANGE WHEN FINAL PROG IS WRITTEN

    public int counter = 0;
    private int available = 0;
    private int size = 0;
    int fixedSize;
    //consumerindex
    int returnIndex;
    //producerindex
    int prodindex;
    int[] myBuffer = new int[fixedSize];



    Buffer(int bufferSize)
    {
        int[] buffer = new int[bufferSize];
        for(int i = 0; i < bufferSize; i++)
        {
            buffer[i] = -1;
        }
        myBuffer = buffer;
        fixedSize = bufferSize;
    }


//This is to insert a number into your buffer
public int insert(int value)
{

    //VERIFIES BUFFER ISN'T FULL
    if(isFull())
    {
        return -1;
    }

    myBuffer[counter] = value;
    this.prodindex = counter;
    counter = (counter + 1) % fixedSize;

    size = (size + 1);

    //This is for your running total
    return value;

}


    public int remove()
    {
        if(isEmpty())
        {
            return -1;
        }
        size--;
        this.returnIndex = available;
        int var = available;
        available = (available + 1) % fixedSize;
        return myBuffer[var];
    }

public boolean isFull()
{
    return this.size == fixedSize;
}


public boolean isEmpty()
{
    return size == 0;
}



public int size()
{
    return this.size;
}


public void returnThis()
{
    System.out.print(Arrays.toString(myBuffer));

}


public int findnextIndex()
{

    return this.returnIndex;
}

}
