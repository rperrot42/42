#include <stdio.h>

int	main()
{
	char			*s = "oui\0non";
	char			*t = "cr%sr\0p";
	char			*quoi = "%s";
	char			c = 'Y';
	int				i = 42;
	long			d = 42;
	unsigned int	k = 42;

	ft_printf("\n--- %%%% ---\n");
	ft_printf(" [%d]\n", ft_printf("1) %"));
	ft_printf(" [%d]\n", ft_printf("2) %%"));
	ft_printf(" [%d]\n", ft_printf("3) %%%c", c));
	ft_printf(" [%d]\n", ft_printf("4) %%%%"));
	ft_printf("\n--- %%c ---\n");
	ft_printf(" [%d]\n", ft_printf("1) %%c = %c", c));
	ft_printf(" [%d]\n", ft_printf("2) %%c = %c", s[0]));
	ft_printf(" [%d]\n", ft_printf("3) %%c = %c", "")); //???segfault???
	ft_printf(" [%d]\n", ft_printf("4) %%c = %c", s));
	ft_printf(" [%d]\n", ft_printf("5) %%c = %c", "\0")); //???segfault???
	ft_printf(" [%d]\n", ft_printf("6) %%c = %c", '\0'));
	ft_printf(" [%d]\n", ft_printf("7) %%c = %c", 0));
	ft_printf(" [%d]\n", ft_printf("8) %%c = %c", (char)NULL));
	ft_printf(" [%d]\n", ft_printf("9) %%c = %c", -1)); //???segfault???
	//ft_printf(" [%d]\n", ft_printf("10) %%c = %c", ''));
	ft_printf("\n--- %%s ---\n");
	ft_printf(" [%d]\n", ft_printf("1) %%s = %s", s));
	ft_printf(" [%d]\n", ft_printf("2) %%s = %s", "oui\0non"));
	ft_printf(" [%d]\n", ft_printf("3) %%s = %s", ""));
	ft_printf(" [%d]\n", ft_printf("4) %%s = %s", "\0"));
	ft_printf(" [%d]\n", ft_printf("5) %%s = %s", 0));
	ft_printf(" [%d]\n", ft_printf("6) %%s = %s", (char *)NULL));
	//ft_printf(" [%d]\n", ft_printf("7) %%s = %s", -1)); segfault
	ft_printf("\n--- %%p ---\n");
	ft_printf(" [%d] -- ", ft_printf("1) %%p = %p", &c));
	printf("%p\n", &c);
	ft_printf(" [%d]\n", ft_printf("2) %%p = %p", NULL));
	ft_printf(" [%d]\n", ft_printf("3) %%p = %p", 0));
	ft_printf(" [%d]\n", ft_printf("4) %%p = %p", -9223372036854775808));
	ft_printf(" [%d]\n", ft_printf("5) %%p = %p", 1));
	ft_printf(" [%d]\n", ft_printf("6) %%p = %p", (void *)9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999));
	ft_printf(" [%d]\n", ft_printf("7) %%p = %p, %p", 0, 0));
	ft_printf("\n--- %%d ---\n");
	ft_printf(" [%d]\n", ft_printf("1) %%d = %d", i));
	ft_printf(" [%d]\n", ft_printf("2) %%d = %d", 0));
	ft_printf(" [%d]\n", ft_printf("3) %%d = %d", -1));
	ft_printf(" [%d]\n", ft_printf("4) %%d = %d", 9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999));
	ft_printf(" [%d]\n", ft_printf("5) %%d = %d", -9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999));
	ft_printf(" [%d]\n", ft_printf("6) %%d = %d", 10000000000));
	ft_printf(" [%d]\n", ft_printf("7) %%d = %d", -10000000000));
	ft_printf(" [%d]\n", ft_printf("8) %%d = %d", 118446744073709551619));
	ft_printf(" [%d]\n", ft_printf("9) %%d = %d", -118446744073709551616));
	ft_printf(" [%d]\n", ft_printf("10) %%d = %d", '0'));
	ft_printf(" [%d]\n", ft_printf("11) %%d = %d", ""));
	ft_printf("\n--- %%i ---\n");
	ft_printf(" [%d]\n", ft_printf("1) %%i = %i", i)); //%d = %i
	ft_printf("\n--- %%u ---\n");
	ft_printf(" [%d]\n", ft_printf("1) %%u = %u", k));
	ft_printf(" [%d]\n", ft_printf("2) %%u = %u", -1));
	ft_printf(" [%d]\n", ft_printf("3) %%u = %u", '0'));
	ft_printf(" [%d]\n", ft_printf("4) %%u = %u", ""));
	ft_printf("\n--- %%x ---\n");
	ft_printf(" [%d]\n", ft_printf("1) %%x = %x", i));
	ft_printf("\n--- %%X ---\n");
	ft_printf(" [%d]\n", ft_printf("1) %%X = %X", -1));
	ft_printf(" [%d]\n", ft_printf("2) %%X = %X", 0));
	ft_printf(" [%d]\n", ft_printf("3) %%X = %X", (int)NULL));
	ft_printf(" [%d]\n", ft_printf("4) %%X = %X", ""));
	ft_printf("\n--- -1 ---\n");
	ft_printf(" [%d]\n", ft_printf(NULL));
	//ft_printf(" [%d]\n", ft_printf('d')); segfault
	ft_printf(" [%d]\n", ft_printf('\0'));
	ft_printf(" [%d]\n", ft_printf(0));
	ft_printf(" [%d]\n", ft_printf("%"));
	ft_printf(" [%d]\n", ft_printf("%\0"));
	//ft_printf(" [%d]\n", ft_printf(-1)); segfault
	ft_printf(" [%d]\n", ft_printf(s));
	// ft_printf("-0-0-0-\n");
	//ft_printf(" [%d]\n", ft_printf(t));// peut segfault
	// ft_printf("-0-0-0-\n");
	//ft_printf(" [%d]\n", ft_printf("%s"));
	//ft_printf(" [%d]\n", ft_printf(quoi)); segfault
	ft_printf(" [%d]\n", ft_printf(t, s));
	ft_printf(" [%d]\n", ft_printf(t, t, s));
	ft_printf(" [%d]\n", ft_printf(""));
	ft_printf(" [%d]\n", ft_printf("",s));
	ft_printf(" [%d]\n", ft_printf("",""));
	ft_printf(" [%d]\n", ft_printf(s,s));
	ft_printf(" [%d]\n", ft_printf("",s,s));
	ft_printf(" [%d]\n", ft_printf("non ou %s ", "oui", "ou", "non"));
	ft_printf(" [%d]\n", ft_printf("%tt\0"));
	ft_printf(" [%d]\n", ft_printf("%kk\0"));
	ft_printf(" [%d]\n", ft_printf("%bb\0"));
	ft_printf(" [%d]\n", ft_printf("%qq\0"));
	ft_printf(" [%d]\n", ft_printf("%ww\0"));
	//ft_printf(" [%d]\n", ft_printf("non ou %s %s %s %s %s %s %s %s")); segfault
}

/*
https://koor.fr/C/cstdarg/va_start.wp
https://learn.microsoft.com/fr-fr/cpp/c-runtime-library/reference/va-arg-va-copy-va-end-va-start?view=msvc-170
https://translate.google.fr/?sl=auto&tl=fr&text=%E2%80%A2%20Your%20functions%20should%20not%20quit%20unexpectedly%20(segmentation%20fault%2C%20bus%20error%2C%20double%20free%2C%20etc)%20apart%20from%20undefined%20behaviors.%20If%20this%20happens%2C%20your%20project%20will%20be%20considered%20non%20functional%20and%20will%20receive%20a%200%20during%20the%20evaluation.%0A%0A%E2%80%A2%20All%20heap%20allocated%20memory%20space%20must%20be%20properly%20freed%20when%20necessary.%20No%20leaks%20will%20be%20tolerated.%0A%0A%E2%80%A2%20If%20the%20subject%20requires%20it%2C%20you%20must%20submit%20a%20Makefile%20which%20will%20compile%20your%20source%20files%20to%20the%20required%20output%20with%20the%20flags%20-Wall%2C%20-Wextra%20and%20-Werror%2C%20use%20cc%2C%20and%20your%20Makefile%20must%20not%20relink.%0A%0A%E2%80%A2%20Your%20Makefile%20must%20at%20least%20contain%20the%20rules%20%24(NAME)%2C%20all%2C%20clean%2C%20fclean%20and%20re.%0A%0A%E2%80%A2%20If%20your%20project%20allows%20you%20to%20use%20your%20libft%2C%20you%20must%20copy%20its%20sources%20and%20its%20associated%20Makefile%20in%20a%20libft%20folder%20with%20its%20associated%20Makefile.%20Your%20project%E2%80%99s%20Makefile%20must%20compile%20the%20library%20by%20using%20its%20Makefile%2C%20then%20compile%20the%20project.%0A%0A%E2%80%A2%20We%20encourage%20you%20to%20create%20test%20programs%20for%20your%20project%20even%20though%20this%20work%20won%E2%80%99t%20have%20to%20be%20submitted%20and%20won%E2%80%99t%20be%20graded.%20It%20will%20give%20you%20a%20chance%20to%20easily%20test%20your%20work%20and%20your%20peers%E2%80%99%20work.%20You%20will%20find%20those%20tests%20especially%20useful%20during%20your%20defence.%20Indeed%2C%20during%20defence%2C%20you%20are%20free%20to%20use%20your%20tests%20and%2For%20the%20tests%20of%20the%20peer%20you%20are%20evaluating.%0A%0A%E2%80%A2%20Submit%20your%20work%20to%20your%20assigned%20git%20repository.%20Only%20the%20work%20in%20the%20git%20reposi-%0Atory%20will%20be%20graded.%20If%20Deepthought%20is%20assigned%20to%20grade%20your%20work%2C%20it%20will%20be%20done%20after%20your%20peer-evaluations.%20If%20an%20error%20happens%20in%20any%20section%20of%20your%20work%20during%20Deepthought%E2%80%99s%20grading%2C%20the%20evaluation%20will%20stop.&op=translate&hl=fr
*/
