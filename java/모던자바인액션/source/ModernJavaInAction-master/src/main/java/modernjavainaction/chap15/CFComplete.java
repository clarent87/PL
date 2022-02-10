package modernjavainaction.chap15;

import static modernjavainaction.chap15.Functions.f;
import static modernjavainaction.chap15.Functions.g;

import java.util.concurrent.CompletableFuture;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

// 483p CompletableFuture 예시
public class CFComplete {

  public static void main(String[] args) throws ExecutionException, InterruptedException {
      ExecutorService executorService = Executors.newFixedThreadPool(10);
      int x = 1337;

      CompletableFuture<Integer> a = new CompletableFuture<>();
      executorService.submit(() -> a.complete(f(x))); // 따로 다른 core에 진입?
      int b = g(x);
      
      // 만약 아래 코드가 한줄이 아니라 100줄이었다면? 여기서 멈추게 되면 문제.. thread 도 하나 낭비고..
      // 이때 만약 아래 코드를 task로 빼서 큐잉 해두면? 그아래 코드는 쭉 진행하고 이 thread는 놀게 할수 있음.
      // 약간 이런 개념이 thenCombine 인듯
      System.out.println(a.get() + b);  

      executorService.shutdown();
  }

}
