/*

    SAMP Money Format by PateeerQ

    First Release:
    09/08/2024 6:50AM

    Last Updated:
    24/10/2024 7:26AM

*/

#define samp_money_format_included

#define MONEYFMT_OUTPUT         24
#define MONEYFMT_CENTPLACEMENT  2

#if defined MONEYFMT_ALWAYS_USECENT
    #define MONEYFMT_USECENT_DEFAULT true
#else
    #define MONEYFMT_USECENT_DEFAULT false
#endif

enum
{
    MONEYFMT_TYPE,
    MONEYFMT_SYMBOL,
    MONEYFMT_GROUPING
};

enum
{
    MONEYFMT_USD,
    MONEYFMT_EUR,
    MONEYFMT_GBP,
    MONEYFMT_IDR,
    MONEYFMT_JPY
};

new
    const moneyfmt_Symbol[][][] =
    {   // TYPE, SYMBOL, GROUPING
        {"USD$", "$", ","},
        {"EUR", "€", ","},
        {"GBP", "£", ","},
        {"IDR", "Rp", "."},
        {"JP¥", "¥", ","}
    };

/*

    FormatMoney(amount, currency, enable_cent, enable_type);
    (!) enable_cent. by enabling this, you will use last 2 digits from your amount values. ex amount: 14000 -> output: $140.00
    (!) enable_type. by enabling this, you will get full money format. ex amount: 14000 -> USD$140.00

*/

stock PATEEER_FormatMoney(amount, currency = MONEYFMT_USD, enable_cent = MONEYFMT_USECENT_DEFAULT, enable_type = false, const delimiter[2] = ".") 
{
	new 
		txt[MONEYFMT_OUTPUT]
	;

	format(txt, MONEYFMT_OUTPUT, "%d", amount);

	new 
        l = strlen(txt)
    ;

	if(l > MONEYFMT_CENTPLACEMENT && enable_cent) 
        strins(txt, delimiter, l - MONEYFMT_CENTPLACEMENT);

    if(l > 5 - (enable_cent ? 0 : 2)) 
        strins(txt, moneyfmt_Symbol[currency][MONEYFMT_GROUPING], l - 5 + (enable_cent ? 0 : 2));

    if(l > 8 - (enable_cent ? 0 : 2)) 
        strins(txt, moneyfmt_Symbol[currency][MONEYFMT_GROUPING], l - 8 + (enable_cent ? 0 : 2));
    
    if(l > 11 - (enable_cent ? 0 : 2)) 
        strins(txt, moneyfmt_Symbol[currency][MONEYFMT_GROUPING], l - 11 + (enable_cent ? 0 : 2));

	if(l <= 2 && enable_cent) 
        format(txt, MONEYFMT_OUTPUT, "%s0.%s", enable_type ? moneyfmt_Symbol[currency][MONEYFMT_TYPE] : moneyfmt_Symbol[currency][MONEYFMT_SYMBOL], txt);
	else 
        format(txt, MONEYFMT_OUTPUT, "%s%s", enable_type ? moneyfmt_Symbol[currency][MONEYFMT_TYPE] : moneyfmt_Symbol[currency][MONEYFMT_SYMBOL], txt);

	return txt;
}

#define FormatMoney PATEEER_FormatMoney
