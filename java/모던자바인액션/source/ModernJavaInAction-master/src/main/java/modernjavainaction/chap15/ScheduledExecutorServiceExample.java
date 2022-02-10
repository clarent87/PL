package modernjavainaction.chap15;

import java.util.concurrent.Executors;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.TimeUnit;

public class ScheduledExecutorServiceExample {

  public static void main(String[] args) {
      ScheduledExecutorService scheduledExecutorService = Executors.newScheduledThreadPool(1);

      work1(); // 이거 종료 되면 아래 코드 실행
      scheduledExecutorService.schedule(ScheduledExecutorServiceExample::work2, 10, TimeUnit.SECONDS); // 이것도 thread 먹긴 하는데..

      // 종료전에 submit된 task는 전부 실행함
      scheduledExecutorService.shutdown();

      // 여튼 핵심은 block 되는건 좋지 않다는.. 뭐 그런거.
  }

  public static void work1() {
    System.out.println("Hello from Work1!");
  }

  public static void work2() {
    System.out.println("Hello from Work2!");
  }

}
