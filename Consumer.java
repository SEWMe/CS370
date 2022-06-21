
public class Consumer extends java.lang.Thread  {

    final Buffer refBuffer;
    int ID;
    int consumeElements;
    int exitNum;
    int checkSum = 0;


    Consumer(Buffer Buff, int consumeElements, int id) {
        this.refBuffer = Buff;
        this.consumeElements = consumeElements;
        this.ID = id;

    }

    public Buffer getRefBuffer() {
        return refBuffer;
    }

    @Override
    public void run() {
        while (consumeElements != 0) {
            synchronized (refBuffer) {
                while (refBuffer.isEmpty()) {
                    try {
                        refBuffer.wait();
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
                try {


                        int consumedItem = refBuffer.remove();
                        checkSum += consumedItem;

                        consumeElements--;
                        //
                        // Exit Section
                    System.out.println("\033[0;4mConsumer " + ID + " consumed " + consumedItem + " from Index " + refBuffer.findnextIndex() + " at time " + Coordinator.getTime() + "\033[0;0m");
                        refBuffer.notify();

                } catch (IllegalStateException e) {
                    e.printStackTrace();
                }


            }



        }

    }







    public int getCheckSum()
    {
        return this.checkSum;
    }
}
