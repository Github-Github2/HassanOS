#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

int main() {
    printf("Welcome to Catpedia, the Cat Encyclopedia\n");

    char string[500];
    if (fgets(string, sizeof(string), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    // Removing the newline character
    string[strcspn(string, "\n")] = 0;

    // Convert input to lowercase for case-insensitive comparison
    for (int i = 0; string[i]; i++) {
        string[i] = tolower(string[i]);
    }

    if (strstr(string, "siamese") != NULL) {
		printf("The Siamese cat is one of the most distinctly known Asian cats. Its face is dark while its body is in contrast being white.\n");
        printf("Its other name is the Balinese cat. It originates from Thailand, specifically the Ayutthata Empire. It derives from the Wichianmat Family.\n");
        printf("It is called the Siamese as Siam is the name for Thailand. The Siamese cat also has blue eyes, and its nicknames are Mese, Meezer.\n");
    } else if (strstr(string, "british shorthair") != NULL) {
        printf("The British Shorthair is a pedigreed breed of the domestic British cat. The most familiar variant is the British Blue with its notable grey-blue coat and copper eyes.\n");
        printf("It is one of the most ancient cats known to man. It is registered in the GCCF, also known as the UK's Governing Council of the Cat Fancy.\n");
        printf("Its name makes sense as it has short hair.\n");
    } else if (strstr(string, "persian") != NULL) {
		printf("The Persian Cat, also known as the Persian Longhair or Shirazi, is a longhaired cat breed characterized by their round face and short muzzle.\n");
        printf("The first documented ancestors of the Persian cat might have been imported to Italy from Khorsan, but it cannot be proven.\n");
        printf("It is not clear when long-haired cats first appeared, as there are no known long-haired specimens of the African wildcat, the ancestor of the domestic species.\n");
        printf("The variants of the Persian Cat include the Himalayan, Exotic Shorthair, or the Chinchilla Longhair.\n");
    } else if (strstr(string, "maine coon") != NULL) {
        printf("The Maine Coon is a large domesticated cat breed. It is one of the oldest natural breeds in North America.\n");
        printf("It is also known as the American Longhair. The Maine Coon have distinctive physical appearance and Hunting skills.\n");
        printf("The Maine Coon originated in Maine were it has surrounded by myths. One of the myths is it is a hybrid of a Raccoon or Bobcat.\n");
        printf("Cosey is a Maine Coon who won the first cat show in the United States of America.\n");
    } else if (strstr(string, "abyssinian") != NULL) {
        printf("The Abyssinian Cat is just what its name says it originated from Abyssinia also known as modern-day Ethiopia.\n");
        printf("Zula is the first-ever Abyssinian cat recorded and is in an exhibit in Holland.\n");
        printf("A Common Nickname of the Abyssinian Cat is the Abys not to be confused with the Swiss politician Rageth Abys.\n");
        printf("Veterinarian Joan O Joshua says that the Abyssinian Cat is like the Burmese Cat with the Dog-like attachment to their Owners.\n");
    } else if (strstr(string, "burmese") != NULL) {
        printf("The Burmese Cat like its name suggests it originates from Burma or modern-day Myanmar.\n");
        printf("Most Modern Burmese Cats are descendants of Wong mau, a cat which got imported from Burma (Myanmar) to The United States.\n");
        printf("A Veterinary Study shows that Burmese cats have higher Prevalence to Diabetes.\n");
        printf("The Skin of the Burmese cat is Copper colored as even in Thai the name of the Burmese cat means Copper color.\n");
    } else if (strstr(string, "russian blue") != NULL) {
        printf("The Russian Blue as it is says in the name is from Russia to be specific Arkhangelsk or Archangel and that is why it is also named The Archangel cat.\n");
        printf("The Russian Blue is Also hypoallergenic as it doesn't shed as much as other cats would that is the reason people have allergies it is because of the Shedding.\n");
        printf("The Russian Blue is also in pop culture as Arlene in Garfield the popular comic strip is a Russian Blue. The Internet Craze Nyan cat is A Russian Blue.\n");
        printf("The Russian Blue has bright green eyes, pinkish lavender or mauve paws, two layers of short thick fur, and a blue-grey-black coat.\n");
    } else if (strstr(string, "somali") != NULL) {
        printf("The Somali Cat is a genetically modified version of the Abyssinian Cat, it has the name Somali to honour they neighbouring country even though it was made in the USA.\n");
        printf("In the 1940s, a British breeder named Janet Robertson exported some Abyssinian kittens to Australia, New Zealand and North America. Descendants of these cats occasionally produced kittens with long or fuzzy coats. In 1963, Mary Mailing, a breeder from Canada, entered one into a local pet show. Ken McGill, the show's judge, asked for one for breeding purposes.\n");
        printf("The Somali Cat is a longhaired just like the Persian cat and Maine Coon.\n");
    } else if (strstr(string, "brazilian shorthair") != NULL) {
        printf("The Brazilian Shorthair is the first cat breed from Brazil to be known internationally.The breed was purportedly started by a cat breeder named Paulo Samuel Ruschi, who founded the first Cat Federation in Brazil and the first Cat Club in Rio de Janeiro.\n");
		printf("The Brazilian Shorthairis an indoor and outboor cat.The breed had developed without rules or special cares; until, in the 1980s, Brazilian-born engineer Paulo Samuel Ruschi.\n");
		printf("Street and feral cats from Brazil are claimed to be a distinct landrace within the South American cat population, similar to the Maine Coon within the North American cat population.\n");
    } else if (strstr(string, "sphynx") != NULL) {
        printf("The Sphynx cat also known as the Canadian Sphynx is a cat known for its lack of Fur. The Hairlessness is a genetic mutation.\n");
		printf("the Sphynx was developed through selective breeding of these animals, starting in the 1960s. If You would like to see the list of charecterstics.\n");
        printf("Do you want to see the list of characteristics? (yes/no): ");

        char answer[10];
        scanf("%s", answer);

        if (strcmp(answer, "yes") == 0) {
            printf("Wedge-shaped heads with prominent cheekbones.\n");
            printf("Large, lemon-shaped eyes.\n");
			printf("Very large ears with hair on inside, but soft down on outside base.\n");
			printf("Very large ears with hair on inside, but soft down on outside base.\n");
			printf("Medium length torso, barrel-chested, and full, round abdomen, sometimes called a pot belly.\n");
			printf("Paw pads thicker than other cats, giving the appearance of walking on cushions.\n");
			printf("Whiplike, tapering tail from body to tip, (sometimes with fur all over tail or a puff of fur on the tip, like a lion).\n");
			printf("Muscular body.\n");
            printf("Would you like to learn more about the breed? (return/exit): ");
            char choice[10];
            scanf("%s", choice);
            if (strcmp(choice, "return") == 0) {
                printf("The contemporary breed of Sphynx cat is distinct from the Russian hairless cat breeds, like Peterbald and Donskoy.\n");
                printf("The Canadian Sphynx breed was started in 1966 in Toronto, Ontario when a hairless male kitten named Prune was born to a black and white domestic shorthair queen (Elizabeth).\n");
            } else {
                printf("Self Detonation.\n");
                for (int i = 3; i > 0; i--) {
                    printf("%d...\n", i);
                    sleep(1);
                }
                printf("Bye.\n");
                return 1;
            }
        } else {
            printf("The contemporary breed of Sphynx cat is distinct from the Russian hairless cat breeds, like Peterbald and Donskoy.\n");
            printf("The Canadian Sphynx breed was started in 1966 in Toronto, Ontario when a hairless male kitten named Prune was born to a black and white domestic shorthair queen (Elizabeth).\n");
        }
    } else if (strstr(string, "scottish fold") != NULL) {
		printf("The Scottish Fold is a distinctive breed of domestic cat characterised by a natural dominant gene mutation associated with osteochondrodysplasia.\n");
		printf("This genetic anomaly affects the cartilage across the body causing its ears to fold and that is why the name is called the Scottish Fold.\n");
		printf("It has the Nickname of Scot fold.The original Scottish Fold was a white barn cat named Susie, who was found at a farm near Coupar Angus in Tayside, Scotland, in 1961. Susie's ears had an unusual fold in their middle, making her resemble an owl.\n");
	} else if (strstr(string, "dragon li") != NULL) {
		printf("The Dragon Li is a recently established Chinese breed of domestic cat (also called Chinese Li Hua or China Li Hua as a standardized breed, depending on breed registry).\n");
		printf("It was developed from a common landrace of cats in China,known as 貍花貓,which translates to the 'fox flower cat'.\n");
		printf("The native cats are featured in some Chinese folklore stories. The derived standardized breed is recognized by China's Cat Aficionado Association (CAA), and was for a time by the US-based, international Cat Fanciers' Association (CFA), later revoked.\n");
	} else if (strstr(string "bengal") != NULL) {
		
	} else {
        printf("Cat information not found. Please check your spelling and try again.\n");
    }

    return 0;
}
