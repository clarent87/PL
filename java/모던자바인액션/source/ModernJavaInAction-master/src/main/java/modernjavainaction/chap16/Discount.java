package modernjavainaction.chap16;

import static modernjavainaction.chap16.Util.delay;
import static modernjavainaction.chap16.Util.format;

public class Discount {

  public enum Code {
    NONE(0), SILVER(5), GOLD(10), PLATINUM(15), DIAMOND(20);

    private final int percentage;

    Code(int percentage) {
      this.percentage = percentage;
    }
  }

  public static String applyDiscount(Quote quote) {
    return quote.getShopName() + " price is " + Discount.apply(quote.getPrice(), quote.getDiscountCode());
  }

  // 할인 가격 계산
  private static double apply(double price, Code code) {
    delay();
    return format(price * (100 - code.percentage) / 100); // 숫자 출력 format을 제어할수 있음
  }

}
