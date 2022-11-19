// #include "main.h"
/*gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c*/
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#define HEX                              \
    {                                    \
        '0', '1', '2', '3', '4',         \
            '5', '6', '7', '8', '9',     \
            'A', 'B', 'C', 'D', 'E', 'F' \
    }
#define BINARY   \
    {            \
        '0', '1' \
    }
#define OCTAL                  \
    {                          \
        '0', '1', '2', '3',    \
            '4', '5', '6', '7' \
    }

/** struct function - struct containing
 * an identifier and function pointer
 *@id: identifier for the function
 *@func: a pointer to function
 */
struct function
{
    char id;
    char *(*func)(va_list *);
};
int _printf(const char *format, ...);
char *(*get_fuction(char c))(va_list *);
/*sting and char conversion*/
char *ctostr(va_list *ap);
char *tostr(va_list *ap);
/* number conversion*/
char *_uitos(va_list *ap);
char *_itos(va_list *ap);
/*conversion to hex, binary and octal*/
char *_itox(va_list *ap);
char *_itoX(va_list *ap);
char *_itob(va_list *ap);
char *ito_oc(va_list *ap);
/* custom conversions*/
char *rot13(va_list *ap);
char *rev(va_list *ap);
char *custom_str(va_list *ap);
/*helper functions*/
int _strlen(char *s);
char *conv_to_xob(unsigned int n, char flag, char arr[]);
char *num_to_str(unsigned int n, int negative);

/**
 * _printf - print formatted string
 * @format: string to print
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    char *buffer, *s = "";
    int i, len_buff, j, n;
    char *(*fuc)(va_list *);
    va_list ap;
    i = len_buff = j = 0;
    va_start(ap, format);
    buffer = malloc(sizeof(char *));
    if (buffer == NULL)
    {
        return (0);
    }

    while (format[i])
    {
        if (format[i] != '%')
        {
            buffer[len_buff++] = format[i++];
        }
        else
        {
            i++;
            if (format[i] == '%')
            {
                buffer[len_buff] = '%';
            }
            else
            {
                fuc = get_fuction(format[i]);
                j = 0;
                s = fuc(&ap);
                while (j < _strlen(s))
                {
                    buffer[len_buff++] = s[j];
                    j++;
                }
                free(s);
                i++;
            }
        }
    }
    va_end(ap);
    buffer[len_buff] = '\0';
    n = len_buff > 1024 ? 1024 : len_buff;
    printf("%s\n", buffer);
    while (*buffer != '\0')
    {
        write(1, buffer, n);
        buffer = buffer + n;
        n = len_buff - n;
    }
    return (len_buff);
}

int main(void)
{
    unsigned int i = (unsigned int)INT_MAX + 1024;
    _printf("test 98 binary  %b\nhex %x\nHEX %X\noctal %o", 98, 98, 98, 98);
    int n = printf("Lorem ipsum dolor sit amet consectetur, adipisicing elit. Suscipit, quas a. Assumenda beatae architecto minima odit explicabo! Nostrum eveniet asperiores, nisi dolor commodi soluta voluptate. At, ipsam nostrum praesentium provident perferendis et vero sunt excepturi doloribus corrupti aut temporibus quod nobis veritatis tempora hic voluptas mollitia asperiores. Dignissimos eum, repudiandae numquam commodi, ad voluptatem iure veniam deleniti voluptate consectetur dicta temporibus porro laudantium eaque perferendis, similique tempora illum? Ab at et voluptates recusandae animi illo mollitia, natus exercitationem assumenda rem commodi. Laborum, optio, ratione, laudantium saepe ex molestiae nihil excepturi ad adipisci nostrum ipsa minima voluptates soluta vero maiores velit voluptas impedit omnis accusantium. Tenetur commodi obcaecati, exercitationem, molestiae accusantium fugiat deserunt similique culpa tempore natus et eum unde, sit aliquid est nostrum eius ratione? Blanditiis nulla ratione quisquam provident recusandae natus aut quae ipsum praesentium unde architecto ea distinctio autem incidunt veniam qui molestias, id quaerat illo. Quasi pariatur eveniet totam vitae esse recusandae beatae tenetur, iusto laborum quos eius deserunt, placeat quae minima repellat amet non enim, repellendus velit sint sapiente maiores soluta omnis. Maiores dolor sequi, porro quasi minima illum voluptas ipsum. Perspiciatis, ducimus sequi? Sequi soluta perspiciatis nulla eos velit quis molestias autem, culpa alias similique ea a quam fugit delectus optio minima explicabo aut consectetur harum, hic veritatis? Quidem, illo reprehenderit ab aut, expedita quisquam sit eum quam reiciendis explicabo pariatur eveniet cupiditate inventore officiis voluptatem nostrum aliquam voluptatibus! In esse aspernatur praesentium, facilis et quaerat nobis sequi neque iusto odit dolores laborum quis rerum magni illo vitae repellat sunt quod ducimus itaque incidunt, dolore libero! Fugiat eius sequi incidunt blanditiis minima, alias cupiditate nihil, placeat rem maxime expedita voluptate et necessitatibus ipsam, libero nobis! Veniam dignissimos tempore nemo dolorum quod adipisci omnis laboriosam repellat iste asperiores ipsam officiis eum ab labore ducimus tenetur sint culpa vero perferendis est, expedita consectetur! Animi delectus pariatur laborum, illum natus perspiciatis nostrum possimus, illo vero exercitationem est quidem autem dolorum provident repellat architecto beatae! Reiciendis soluta impedit dolorum ipsam ea, aut odio hic dolor, earum, velit ipsa! Quibusdam, assumenda, dolorum mollitia repudiandae molestiae at officiis minus ipsam nesciunt quo libero ullam nostrum earum, esse eius voluptate. Error atque repellendus hic quisquam corrupti tempora omnis expedita id maiores minus, consequuntur vero quis dolorem fuga aliquid laboriosam non. Aperiam, eum ratione mollitia dolorem eveniet delectus vero quis ab esse sequi at suscipit autem, debitis aspernatur quod sit excepturi odit dignissimos provident inventore magni accusantium. Dicta provident optio, odit ex hic quibusdam libero! Architecto adipisci quaerat quis distinctio accusamus iure assumenda ad voluptatum cupiditate est omnis odio sint sunt nihil explicabo, nisi nesciunt consequatur, ipsum enim esse voluptas corporis doloremque molestias obcaecati? Nesciunt consectetur commodi repellat ipsum consequuntur accusantium! Voluptatibus illo ipsa cumque rerum tempora quasi corporis. Repudiandae dolores, nemo molestiae assumenda, magni dolorum possimus aspernatur adipisci culpa in ratione tempore! Nulla voluptatibus ex, corrupti rem quia earum natus sint ipsum fugiat ad minus delectus neque? Dolore voluptas eligendi sed earum repellat, perferendis nam vel debitis ipsam iusto cumque nulla ad molestiae nemo explicabo, quia suscipit odit iste, officia expedita enim. Obcaecati aspernatur quidem doloremque quisquam earum amet temporibus? Corrupti id culpa tenetur fuga beatae nemo, eos, assumenda harum in saepe modi sed quod. Rerum earum odio porro sapiente, est, voluptate quam perspiciatis aspernatur commodi dicta possimus maxime vitae labore? Nobis sequi quisquam, id labore adipisci non? Molestiae quasi nemo exercitationem repellendus quis esse, sunt ipsum soluta, veniam eaque iure suscipit doloremque. Ea repudiandae est porro. Facilis nemo iste beatae ullam amet earum voluptates animi, nesciunt quasi dicta sit dolorum saepe, itaque veniam repudiandae cupiditate ea! Iure adipisci nesciunt consequatur voluptates repudiandae architecto, recusandae alias quod magni, praesentium fuga rem obcaecati veritatis aliquid laboriosam porro beatae cupiditate commodi saepe expedita reiciendis iusto nulla. Sequi quis odio quaerat explicabo. Harum perspiciatis dolor nobis expedita! Asperiores recusandae iste fugit dolorem? Optio sequi atque similique harum dolore quaerat rerum quisquam nemo velit voluptas ipsa aspernatur quis magni itaque, debitis blanditiis consectetur nisi odio eius ullam culpa reprehenderit vero fuga accusamus. Nemo laboriosam quis quo pariatur non perferendis accusamus laborum quas blanditiis tenetur unde dolorum ad suscipit maxime excepturi iusto, dolores eius dolore officiis aliquid expedita. Quibusdam sint veritatis, minus ex perspiciatis consectetur hic provident libero aliquam error expedita, eaque doloremque laborum animi fugiat officia nisi officiis consequuntur distinctio repellendus, incidunt exercitationem esse numquam. At dolore neque fugit distinctio eos, maiores tempore voluptate. Ullam, mollitia iure incidunt nesciunt magni dolores quia saepe hic facilis eaque quam sed quis rerum doloribus! Illo doloribus consectetur quam numquam eum mollitia in rem animi! Id nesciunt odio deleniti repudiandae dicta culpa odit assumenda, voluptatibus ducimus eveniet impedit, voluptatem aut architecto saepe error dolore. Ullam rem soluta itaque veniam at facilis amet quod assumenda libero, dolorem sint atque dolor, obcaecati laudantium error adipisci voluptas molestiae vero fugit cupiditate! Tempora est deserunt corporis accusamus vitae dolor in quod dolorum quae incidunt vel recusandae ab, laboriosam, doloremque amet atque nisi facere ipsum, officiis iste ex sapiente rerum distinctio nam. Quia ducimus et possimus consectetur, exercitationem vel doloremque aliquam. Repellendus alias quaerat commodi? Quisquam aliquid ducimus velit doloribus facere cupiditate odit repudiandae porro nisi numquam. Porro alias nobis libero, pariatur neque veritatis error perferendis ipsa inventore doloremque. Ducimus eveniet voluptatibus nostrum numquam non earum obcaecati, quos pariatur fuga culpa laudantium reiciendis veritatis impedit ipsum ex dicta vel dignissimos? Suscipit exercitationem alias quisquam veritatis, porro harum expedita, modi magni fuga illum ex? Non quisquam nostrum mollitia dolorum iure debitis laborum autem quas eligendi, expedita cupiditate molestias culpa quo, similique iste iusto? Optio ullam possimus quia tempore qui praesentium at, quod eaque provident consequatur nihil laborum facere harum neque atque repudiandae omnis perferendis! Saepe, ipsam odit? Aspernatur eaque veniam repellendus quisquam maiores consequuntur temporibus eos, dolores possimus, mollitia ducimus qui. Sed quam ex iusto necessitatibus harum consectetur id quod eaque, minus assumenda, explicabo impedit modi earum obcaecati doloremque recusandae, minima voluptatibus pariatur nesciunt voluptas sequi corrupti! Omnis exercitationem consequatur ratione fugit dicta nulla ea veritatis, nam sunt perferendis est! Deleniti, fugit deserunt, ipsum animi labore asperiores perferendis delectus non totam corporis aperiam natus accusamus. Hic ex et eaque sequi sed accusamus officiis magnam alias! Quas harum nihil nobis quidem!\n");
    _printf("Lorem ipsum dolor sit amet consectetur, adipisicing elit. Suscipit, quas a. Assumenda beatae architecto minima odit explicabo! Nostrum eveniet asperiores, nisi dolor commodi soluta voluptate. At, ipsam nostrum praesentium provident perferendis et vero sunt excepturi doloribus corrupti aut temporibus quod nobis veritatis tempora hic voluptas mollitia asperiores. Dignissimos eum, repudiandae numquam commodi, ad voluptatem iure veniam deleniti voluptate consectetur dicta temporibus porro laudantium eaque perferendis, similique tempora illum? Ab at et voluptates recusandae animi illo mollitia, natus exercitationem assumenda rem commodi. Laborum, optio, ratione, laudantium saepe ex molestiae nihil excepturi ad adipisci nostrum ipsa minima voluptates soluta vero maiores velit voluptas impedit omnis accusantium. Tenetur commodi obcaecati, exercitationem, molestiae accusantium fugiat deserunt similique culpa tempore natus et eum unde, sit aliquid est nostrum eius ratione? Blanditiis nulla ratione quisquam provident recusandae natus aut quae ipsum praesentium unde architecto ea distinctio autem incidunt veniam qui molestias, id quaerat illo. Quasi pariatur eveniet totam vitae esse recusandae beatae tenetur, iusto laborum quos eius deserunt, placeat quae minima repellat amet non enim, repellendus velit sint sapiente maiores soluta omnis. Maiores dolor sequi, porro quasi minima illum voluptas ipsum. Perspiciatis, ducimus sequi? Sequi soluta perspiciatis nulla eos velit quis molestias autem, culpa alias similique ea a quam fugit delectus optio minima explicabo aut consectetur harum, hic veritatis? Quidem, illo reprehenderit ab aut, expedita quisquam sit eum quam reiciendis explicabo pariatur eveniet cupiditate inventore officiis voluptatem nostrum aliquam voluptatibus! In esse aspernatur praesentium, facilis et quaerat nobis sequi neque iusto odit dolores laborum quis rerum magni illo vitae repellat sunt quod ducimus itaque incidunt, dolore libero! Fugiat eius sequi incidunt blanditiis minima, alias cupiditate nihil, placeat rem maxime expedita voluptate et necessitatibus ipsam, libero nobis! Veniam dignissimos tempore nemo dolorum quod adipisci omnis laboriosam repellat iste asperiores ipsam officiis eum ab labore ducimus tenetur sint culpa vero perferendis est, expedita consectetur! Animi delectus pariatur laborum, illum natus perspiciatis nostrum possimus, illo vero exercitationem est quidem autem dolorum provident repellat architecto beatae! Reiciendis soluta impedit dolorum ipsam ea, aut odio hic dolor, earum, velit ipsa! Quibusdam, assumenda, dolorum mollitia repudiandae molestiae at officiis minus ipsam nesciunt quo libero ullam nostrum earum, esse eius voluptate. Error atque repellendus hic quisquam corrupti tempora omnis expedita id maiores minus, consequuntur vero quis dolorem fuga aliquid laboriosam non. Aperiam, eum ratione mollitia dolorem eveniet delectus vero quis ab esse sequi at suscipit autem, debitis aspernatur quod sit excepturi odit dignissimos provident inventore magni accusantium. Dicta provident optio, odit ex hic quibusdam libero! Architecto adipisci quaerat quis distinctio accusamus iure assumenda ad voluptatum cupiditate est omnis odio sint sunt nihil explicabo, nisi nesciunt consequatur, ipsum enim esse voluptas corporis doloremque molestias obcaecati? Nesciunt consectetur commodi repellat ipsum consequuntur accusantium! Voluptatibus illo ipsa cumque rerum tempora quasi corporis. Repudiandae dolores, nemo molestiae assumenda, magni dolorum possimus aspernatur adipisci culpa in ratione tempore! Nulla voluptatibus ex, corrupti rem quia earum natus sint ipsum fugiat ad minus delectus neque? Dolore voluptas eligendi sed earum repellat, perferendis nam vel debitis ipsam iusto cumque nulla ad molestiae nemo explicabo, quia suscipit odit iste, officia expedita enim. Obcaecati aspernatur quidem doloremque quisquam earum amet temporibus? Corrupti id culpa tenetur fuga beatae nemo, eos, assumenda harum in saepe modi sed quod. Rerum earum odio porro sapiente, est, voluptate quam perspiciatis aspernatur commodi dicta possimus maxime vitae labore? Nobis sequi quisquam, id labore adipisci non? Molestiae quasi nemo exercitationem repellendus quis esse, sunt ipsum soluta, veniam eaque iure suscipit doloremque. Ea repudiandae est porro. Facilis nemo iste beatae ullam amet earum voluptates animi, nesciunt quasi dicta sit dolorum saepe, itaque veniam repudiandae cupiditate ea! Iure adipisci nesciunt consequatur voluptates repudiandae architecto, recusandae alias quod magni, praesentium fuga rem obcaecati veritatis aliquid laboriosam porro beatae cupiditate commodi saepe expedita reiciendis iusto nulla. Sequi quis odio quaerat explicabo. Harum perspiciatis dolor nobis expedita! Asperiores recusandae iste fugit dolorem? Optio sequi atque similique harum dolore quaerat rerum quisquam nemo velit voluptas ipsa aspernatur quis magni itaque, debitis blanditiis consectetur nisi odio eius ullam culpa reprehenderit vero fuga accusamus. Nemo laboriosam quis quo pariatur non perferendis accusamus laborum quas blanditiis tenetur unde dolorum ad suscipit maxime excepturi iusto, dolores eius dolore officiis aliquid expedita. Quibusdam sint veritatis, minus ex perspiciatis consectetur hic provident libero aliquam error expedita, eaque doloremque laborum animi fugiat officia nisi officiis consequuntur distinctio repellendus, incidunt exercitationem esse numquam. At dolore neque fugit distinctio eos, maiores tempore voluptate. Ullam, mollitia iure incidunt nesciunt magni dolores quia saepe hic facilis eaque quam sed quis rerum doloribus! Illo doloribus consectetur quam numquam eum mollitia in rem animi! Id nesciunt odio deleniti repudiandae dicta culpa odit assumenda, voluptatibus ducimus eveniet impedit, voluptatem aut architecto saepe error dolore. Ullam rem soluta itaque veniam at facilis amet quod assumenda libero, dolorem sint atque dolor, obcaecati laudantium error adipisci voluptas molestiae vero fugit cupiditate! Tempora est deserunt corporis accusamus vitae dolor in quod dolorum quae incidunt vel recusandae ab, laboriosam, doloremque amet atque nisi facere ipsum, officiis iste ex sapiente rerum distinctio nam. Quia ducimus et possimus consectetur, exercitationem vel doloremque aliquam. Repellendus alias quaerat commodi? Quisquam aliquid ducimus velit doloribus facere cupiditate odit repudiandae porro nisi numquam. Porro alias nobis libero, pariatur neque veritatis error perferendis ipsa inventore doloremque. Ducimus eveniet voluptatibus nostrum numquam non earum obcaecati, quos pariatur fuga culpa laudantium reiciendis veritatis impedit ipsum ex dicta vel dignissimos? Suscipit exercitationem alias quisquam veritatis, porro harum expedita, modi magni fuga illum ex? Non quisquam nostrum mollitia dolorum iure debitis laborum autem quas eligendi, expedita cupiditate molestias culpa quo, similique iste iusto? Optio ullam possimus quia tempore qui praesentium at, quod eaque provident consequatur nihil laborum facere harum neque atque repudiandae omnis perferendis! Saepe, ipsam odit? Aspernatur eaque veniam repellendus quisquam maiores consequuntur temporibus eos, dolores possimus, mollitia ducimus qui. Sed quam ex iusto necessitatibus harum consectetur id quod eaque, minus assumenda, explicabo impedit modi earum obcaecati doloremque recusandae, minima voluptatibus pariatur nesciunt voluptas sequi corrupti! Omnis exercitationem consequatur ratione fugit dicta nulla ea veritatis, nam sunt perferendis est! Deleniti, fugit deserunt, ipsum animi labore asperiores perferendis delectus non totam corporis aperiam natus accusamus. Hic ex et eaque sequi sed accusamus officiis magnam alias! Quas harum nihil nobis quidem!\n");
    _printf("test s %s and char %c", "string", 'c');
    _printf("test int %i\ndecimal %d\nunsigned int %u", 150, -150, i);
    _printf("test revere  %r\nrot13 %R", "thgir", "pnc");
    _printf("%S", "test new line \n test tab \t");
    return 0;
}

char *(*get_fuction(char c))(va_list *)
{
    int i = 0;
    struct function funcs[] =
        {
            {'c', ctostr},
            {'s', tostr},
            {'i', _itos},
            {'d', _itos},
            {'b', _itob},
            {'u', _uitos},
            {'x', _itox},
            {'X', _itoX},
            {'o', ito_oc},
            {'r', rev},
            {'R', rot13},
            {'S', custom_str},
            {'\0', NULL},
        };
    while (funcs[i].id != '\0')
    {
        if (funcs[i].id == c)
        {
            return (funcs[i].func);
        }
        i++;
    }
    return (NULL);
}
char *rot13(va_list *ap)
{
    int i = 0, n;
    char *s = va_arg(*ap, char *);
    char *str = malloc(sizeof(char *));
    if (s == NULL || str == NULL)
    {
        return (NULL);
    }
    while (s[i])
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            n = s[i] % 'A';
        }
        else if (s[i] >= 'a' && s[i] <= 'z')
        {
            n = s[i] % 'a';
        }
        else
        {
            str[i] = s[i];
            i++;
            continue;
        }
        n = n + 13;
        n = n % 26;
        str[i] = s[i] < 'a' ? 'A' + n : 'a' + n;
        i++;
    }
    str[i] = '\0';
    return (str);
}

/**
 * rev_string - reverse a string
 * @ap: pointer to argument parameter
 * Return: string in reverse
 */

char *rev(va_list *ap)
{
    int i = 0, j;
    char *s = va_arg(*ap, char *);
    char *rev = malloc(sizeof(char *));
    if (s == NULL || rev == NULL)
    {
        return (NULL);
    }
    j = _strlen(s) - 1;
    while (j >= 0)
    {
        rev[i] = s[j];
        i++;
        j--;
    }
    rev[i] = '\0';
    return (rev);
}
/**
 * custom_str - convert a string to a custom string
 * @ap: pointer to argument parameter
 * Return: a custom string with
 * none printable charater replaced by \x
 * followed by the ASCII code value in
 * hexadecimal (upper case - always 2 characters)
 */
char *custom_str(va_list *ap)
{
    char *s = va_arg(*ap, char *);
    char *hex = "";
    char arr[16] = HEX;
    char *cstm_s = malloc(sizeof(char *));
    int i, j = 0;
    if (cstm_s == NULL)
    {
        return (NULL);
    }
    for (i = 0; s[i]; i++)
    {
        if (s[i] < 32 || s[i] >= 127)
        {
            hex = conv_to_xob(s[i], 'X', arr);
            cstm_s[j++] = '\\';
            cstm_s[j++] = 'x';
            cstm_s[j++] = hex[1] == '\0' ? '0' : hex[0];
            cstm_s[j++] = hex[1] == '\0' ? hex[0] : hex[1];
        }
        else
        {
            cstm_s[j++] = s[i];
        }
    }
    cstm_s[j] = '\0';
    return (cstm_s);
}
/**
 * _itos - convert  int to string
 * @ap: argument parameter
 * Return: an int as string
 */
char *_itos(va_list *ap)
{
    int n = va_arg(*ap, int);
    if (n < 0)
    {
        n = n * -1;
        return (num_to_str(n, 1));
    }
    return (num_to_str(n, 0));
}
/**
 * _uitos - convert unsigned int to string
 * @ap: argument parameter
 * Return: an unsigned int as string
 */
char *_uitos(va_list *ap)
{
    unsigned int n = va_arg(*ap, unsigned int);
    return (num_to_str(n, 0));
}
/**
 * ctostr - char to string
 * @ap: argument parameter
 * Return: char as string
 */
char *ctostr(va_list *ap)
{
    char c = va_arg(*ap, int);
    char *s = malloc(2);
    if (s == NULL)
    {
        return (NULL);
    }
    s[0] = c;
    s[1] = '\0';
    return (s);
}
/**
 * tostr - string
 * @ap: argument parameter
 * Return: string
 */
char *tostr(va_list *ap)
{
    return (va_arg(*ap, char *));
}
/**
 * t_itox - convert unsigned int to hexadecimal in lower case
 * @ap: argument parameter
 * Return: an unsigned int as hexadecimal in lower case
 */
char *_itox(va_list *ap)
{
    char arr[16] = HEX;
    unsigned int n = va_arg(*ap, unsigned int);
    int i;
    for (i = 10; i <= 15; i++) /*convert letter in arr to lower case*/
    {
        arr[i] = arr[i] + 32;
    }
    return (conv_to_xob(n, 'x', arr));
}

/**
 * t_itoX - convert unsigned int to hexadecimal in upper case
 * @ap: argument parameter
 * Return: an unsigned int as hexadecimal in upper case
 */
char *_itoX(va_list *ap)
{
    char arr[16] = HEX;
    unsigned int n = va_arg(*ap, unsigned int);
    return (conv_to_xob(n, 'X', arr));
}
/**
 * t_ito_oc - convert unsigned int to octal
 * @ap: argument parameter
 * Return: an unsigned int as an octal
 */
char *ito_oc(va_list *ap)
{

    char arr[8] = OCTAL;
    unsigned int n = va_arg(*ap, unsigned int);
    return (conv_to_xob(n, 'o', arr));
}
/**
 * t_itob - convert unsigned int to binary
 * @ap: argument parameter
 * Return: an unsigned int as binary
 */
char *_itob(va_list *ap)
{
    char arr[3] = BINARY;
    unsigned int n = va_arg(*ap, unsigned int);
    return (conv_to_xob(n, 'b', arr));
}
/**
 * _strlen - returns the length of a string
 * @s: string
 * Return: length
 */

int _strlen(char *s)
{
    int len;
    len = 0;
    while (*s)
    {
        len++;
        s++;
    }
    return (len);
}
/**
 * conv_to_xob - convert a number to binary or hex or octal
 * @n:number to convert
 * @flag: value to covert to
 * @arr: an array to help with the conversion
 * Return: number converted to either binary,
 * hex or octal as a string
 */
char *conv_to_xob(unsigned int n, char flag, char arr[])
{
    int i, rem, len_S, div;
    char *s = "";
    if (flag == 'b')
    {
        div = 2;
        len_S = 33;
    }
    else if (flag == 'o')
    {
        div = 8;
        len_S = 12;
    }
    else
    {
        div = 16;
        len_S = 8;
    }
    s = malloc(len_S);
    if (s == NULL)
    {
        return (NULL);
    }
    s[len_S] = '\0';
    for (i = len_S - 1; n != 0; i--)
    {
        rem = n % div;
        n = n / div;
        s[i] = arr[rem];
    }
    return (s + i + 1);
}
/**
 * num_to_str - convert a number to a string
 * @n: number to be converted
 * @negative: to specify if the number is negative or not
 * Return: number as a string
 */
char *num_to_str(unsigned int n, int negative)
{
    int digit, i = 0;
    char *s;
    double tens = 1;
    s = malloc(sizeof(char *));
    if (s == NULL)
    {
        return (NULL);
    }
    if (negative)
    {
        s[i++] = '-';
    }
    while (tens * 10 <= n)
    {
        tens *= 10;
    }
    while (tens >= 1)
    {
        digit = n / tens;
        s[i] = digit + '0';
        n = (n - (tens * digit));
        tens /= 10;
        i++;
    }
    s[i] = '\0';
    return (s);
}
