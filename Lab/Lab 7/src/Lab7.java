import java.util.*;
import java.util.concurrent.*;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.ReentrantLock;
import java.util.Scanner;

public class Lab7 {
    // Общие данные
    static List<String> array = new ArrayList<>();
    static char A, B;
    static int multResult = 1;
    static List<String> workResult = new ArrayList<>();

    // Синхронизационные объекты
    static CountDownLatch event1 = new CountDownLatch(1); // Ручной сброс
    static CountDownLatch event2 = new CountDownLatch(1); // Автоматический сброс
    static ReentrantLock criticalSection = new ReentrantLock();
    static Condition condition = criticalSection.newCondition();

    public static void main(String[] args) throws InterruptedException {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Введите размер массива: ");
        int size = scanner.nextInt();

        System.out.println("Введите " + size + " строк:");
        for (int i = 0; i < size; i++) {
            array.add(scanner.next());
        }

        System.out.println("Исходный массив:");
        array.forEach(System.out::println);

        Thread threadWork = new Thread(new WorkTask(array));
        Thread threadMult = new Thread(new MultElementTask(array));

        threadWork.start();
        threadMult.start();

        System.out.println("Введите два символа A и B:");
        A = scanner.next().charAt(0);
        B = scanner.next().charAt(0);


        event1.countDown();


        criticalSection.lock();
        try {
            System.out.println("main: ожидание результата work...");
            condition.await();
            System.out.println("Результат работы потока work:");
            workResult.forEach(System.out::println);
        } finally {
            criticalSection.unlock();
        }


        event2.await();
        System.out.println("Результат работы потока MultElement: " + multResult);


        threadWork.join();
        threadMult.join();

        System.out.println("Программа завершена.");
    }

    static class WorkTask implements Runnable {
        private final List<String> localArray;

        public WorkTask(List<String> array) {
            this.localArray = new ArrayList<>(array);
        }

        @Override
        public void run() {
            try {
                System.out.println("work: ожидание начала работы...");
                event1.await();

                Scanner scanner = new Scanner(System.in);
                System.out.print("work: Введите время отдыха после обработки элемента (мс): ");
                int sleepTime = scanner.nextInt();

                System.out.println("work: начало обработки...");

                criticalSection.lock();
                try {
                    System.out.println("вход в кр. секцию потоком work");
                    for (String s : localArray) {
                        boolean valid = true;
                        for (char c : s.toCharArray()) {
                            if (c < A || c > B) {
                                valid = false;
                                break;
                            }
                        }
                        if (valid) {
                            workResult.add(s);
                            Thread.sleep(sleepTime);
                        }
                    }
                    System.out.println("выход из кр. секции потоком work");
                    condition.signal();
                } finally {
                    criticalSection.unlock();
                }
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    static class MultElementTask implements Runnable {
        private final List<String> localArray;

        public MultElementTask(List<String> array) {
            this.localArray = new ArrayList<>(array);
        }

        @Override
        public void run() {
            try {
                System.out.println("MultElement: ожидание начала работы...");
                event1.await();

                System.out.println("MultElement: начало вычислений...");

                for (String s : localArray) {
                    multResult *= s.length();
                }

                System.out.println("MultElement: вычисления закончены.");
                event2.countDown();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
}
