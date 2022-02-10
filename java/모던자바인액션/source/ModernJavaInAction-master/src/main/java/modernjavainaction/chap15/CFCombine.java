package modernjavainaction.chap15;

import static modernjavainaction.chap15.Functions.f;
import static modernjavainaction.chap15.Functions.g;

import java.util.concurrent.CompletableFuture;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class CFCombine {

  public static void main(String[] args) throws ExecutionException, InterruptedException {
      ExecutorService executorService = Executors.newFixedThreadPool(10);
      int x = 1337;

      CompletableFuture<Integer> a = new CompletableFuture<>();
      CompletableFuture<Integer> b = new CompletableFuture<>();
      CompletableFuture<Integer> c = a.thenCombine(b, (y, z)-> y + z); // 이것도 task가 thread 큐? 로 들어가는 느낌
                                                                        // 즉, a,b 가 쓰레드에서 실행되고 반환되면
                                                                        // 해당 쓰레드에 c가 동작함. 즉 block된 쓰레드가 없음
      executorService.submit(() -> a.complete(f(x)));
      executorService.submit(() -> b.complete(g(x)));

      System.out.println(c.get()); // 근데 main은 역시 block 되긴하네..
      executorService.shutdown();
  }

}
