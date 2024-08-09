# samp-money-format
SAMP money formatting for Global Currencies - Easy to use

## Function

```pawn
// Function
FormatMoney(value, currency, enable_cent, enable_type);
```

## Example How to use

FormatMoney
```pawn
#include <samp-money-format.inc>

main ()
{
    new
      money = 500000
    ;

    printf("%s", FormatMoney(money, MONEYFMT_EUR);
    // Expected output -> €500,000

    printf("%s", FormatMoney(money, MONEYFMT_IDR, _, true);
    // Expected output -> IDR500,000

    printf("%s", FormatMoney(money, MONEYFMT_EUR, true, true);
    // Expected output -> USD$5,000.00
}
````
