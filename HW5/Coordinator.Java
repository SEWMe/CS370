


import java.lang.Exception;
import java.util.Arrays;
import java.util.Random;
import java.time.Instant;
import java.time.Clock;
import java.time.Duration;

class Coordinator {
    public static void main(String[] args) throws InterruptedException {
    
    
        int numProducers = Integer.parseInt(args[3]);
        int buffSize = Integer.parseInt(args[0]);
        int numConsumers = Integer.parseInt(args[2]);
        int seed = Integer.parseInt(args[4]);
        int items = Integer.parseInt(args[1]);



        int IDc = 0;
        int IDp = 0;
        
        int spreadP = items / numProducers;
        int spreadPr = items % numProducers;

        int spreadC = items / numConsumers;
        int spreadCr = items % numConsumers;

        int checksum = 0;
        int checksum1 = 0;






        Producer[] myProducer = new Producer[numProducers];
        Consumer[] myConsumer = new Consumer[numConsumers];
        Buffer b = new Buffer(buffSize);


//creation for producers
        for(int i = 0 ; i < numProducers; i++)
        {
            IDp++;
            if(i == numProducers - 1)
            {
                Producer p = new Producer(b, spreadP + spreadPr, IDp, seed);
                p.start();
                myProducer[i] = p;
            }
            else
            {
                Producer p = new Producer(b, spreadP, IDp, seed);
                p.start();
                myProducer[i] = p;
            }

        }
//creation for consumers
        for(int i = 0 ; i < numConsumers; i++)
        {
            IDc++;
            if(i == numConsumers - 1)
            {
                Consumer c = new Consumer(b, spreadC + spreadCr, IDc);
                c.start();
                myConsumer[i] = c;
            }
            else
            {
                Consumer c = new Consumer(b, spreadC, IDc);
                c.start();
                myConsumer[i] = c;
            }

        }


        //creation for producers
        for(int i = 0 ; i < numProducers; i++)
        {
            Producer p;

            p = myProducer[i];
            p.join();
            checksum += p.getCheckSum();

        }
//creation for consumers
        for(int i = 0 ; i < numConsumers; i++)
        {
        Consumer c;
        c = myConsumer[i];
        c.join();
        checksum1 += c.getCheckSum();

        }

        System.out.println("Producer(s): Finished Producing " + items + " items with checksum being "+  checksum);
        System.out.println("Consumer(s): Finished Consuming " + items + " items with checksum being "+  checksum1);


    }
        







   

    //Call this function from your producer or your consumer to get the time stamp to be displayed
    public static String getTime() {
        Clock offsetClock = Clock.offset(Clock.systemUTC(), Duration.ofHours(-9));
        Instant time = Instant.now(offsetClock);
        String timeString = time.toString();
        timeString = timeString.replace('T', ' ');
        timeString = timeString.replace('Z', ' ');
        return(timeString);
    }
}
