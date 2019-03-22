[ Stack Overflow ](https://stackoverflow.com)

  1.   2. [ ](https://stackexchange.com/users/?tab=inbox "Recent inbox messages")
  3. [ ](https://stackexchange.com/users/?tab=reputation "Recent achievements: reputation, badges, and privileges earned")
  4.   5. [ ](https://stackexchange.com "A list of all 175 Stack Exchange sites")
  6. [Log In](https://stackoverflow.com/users/login?ssrc=head&returnurl=https%3a%2f%2fstackoverflow.com%2fquestions%2f51923257%2ffor-elf-file-how-to-tell-which-section-contains-execution-binary-code) [Sign Up](https://stackoverflow.com/users/signup?ssrc=head&returnurl=%2fusers%2fstory%2fcurrent)
  7. ### [current community](https://stackoverflow.com)

    * [ Stack Overflow  ](https://stackoverflow.com)

[help](https://stackoverflow.com/help) [chat](https://chat.stackoverflow.com)

    * [ Meta Stack Overflow  ](https://meta.stackoverflow.com)

###  your communities

[Sign
up](https://stackoverflow.com/users/signup?ssrc=site_switcher&returnurl=%2fusers%2fstory%2fcurrent)
or [log
in](https://stackoverflow.com/users/login?ssrc=site_switcher&returnurl=https%3a%2f%2fstackoverflow.com%2fquestions%2f51923257%2ffor-
elf-file-how-to-tell-which-section-contains-execution-binary-code) to
customize your list.

### [more stack exchange communities](https://stackexchange.com/sites)

[company blog](https://stackoverflow.blog)

    * [ Tour  Start here for a quick overview of the site  ](/tour)
    * [ Help Center  Detailed answers to any questions you might have  ](/help)
    * [ Meta  Discuss the workings and policies of this site  ](https://meta.stackoverflow.com)
    * [ About Us  Learn more about Stack Overflow the company  ](https://stackoverflow.com/company/about)
    * [ Business  Learn more about hiring developers or posting ads with us  ](https://www.stackoverflowbusiness.com/?ref=topbar_help)

By using our site, you acknowledge that you have read and understand our
[Cookie Policy](https://stackoverflow.com/legal/cookie-policy), [Privacy
Policy](https://stackoverflow.com/legal/privacy-policy), and our [Terms of
Service](https://stackoverflow.com/legal/terms-of-service/public).

  1.   2. [ Home ](/)
  3.     1. Public
    2. [ Stack Overflow ](/questions)
    3. [ Tags ](/tags)
    4. [ Users ](/users)
    5. [ Jobs ](/jobs?med=site-ui&ref=jobs-tab)
  4.     1. Teams 
    2. [ Create Team ](https://stackoverflow.com/teams "A private, secure home for your team's questions and answers. Starts at $10/month")

Q&A for work. A dedicated place to share your team’s knowledge.

# [For ELF file, how to tell which section contains execution binary
code?](/questions/51923257/for-elf-file-how-to-tell-which-section-contains-
execution-binary-code)

[ Ask Question ](/questions/ask)

3

I am studying ELF and having a doubt for a while. I tried to search for the
answer but in vain. I'd apprciated if somebody could give me the answer or
guide me to the place to find an answer.

Almost all the documents I read about ELF said .text section contains
executable binary code (and .data contains data....). However, when I used
readelf to see the sections contain in an obj file, I saw no .text section but
a section called i.main which contains the executable code (from the code
contained in this section I found the machine code). The following shows the
sections parsed by readelf

`Section Headers: [Nr] Name Type Addr Off Size ES Flg Lk Inf Al [ 0] NULL
00000000 000000 000000 00 0 0 0 [ 1] i.main PROGBITS 00000000 000034 00000a 00
AX 0 0 2 [ 2] .arm_vfe_header PROGBITS 00000000 000040 000004 00 0 0 4 [ 3]
.comment PROGBITS 00000000 000044 0001c6 00 0 0 1 [ 4] .debug_frame PROGBITS
00000000 00020a 00003c 00 0 0 1 [ 5] .debug_info PROGBITS 00000000 000246
000088 00 0 0 1 [ 6] .debug_info PROGBITS 00000000 0002ce 0000dc 00 0 0 1 [ 7]
.debug_line PROGBITS 00000000 0003aa 000030 00 0 0 1 [ 8] .debug_line PROGBITS
00000000 0003da 000044 00 0 0 1 [ 9] .debug_loc PROGBITS 00000000 00041e
000014 00 0 0 1 [10] .debug_macinfo PROGBITS 00000000 000432 000308 00 0 0 1
[11] .debug_pubnames PROGBITS 00000000 00073a 00001b 00 0 0 1 [12]
__ARM_grp..debug_ GROUP 00000000 000758 000008 04 14 14 4 [13] .debug_abbrev
PROGBITS 00000000 000760 0005a4 00 G 0 0 1 [14] .symtab SYMTAB 00000000 000d04
000110 10 21 13 4 [15] .rel.debug_frame REL 00000000 000e14 000010 08 14 4 4
[16] .rel.debug_info REL 00000000 000e24 000018 08 14 5 4 [17] .rel.debug_info
REL 00000000 000e3c 000038 08 14 6 4 [18] .rel.debug_line REL 00000000 000e74
000008 08 14 8 4 [19] .rel.debug_pubnam REL 00000000 000e7c 000008 08 14 11 4
[20] .shstrtab STRTAB 00000000 000e84 0000f2 00 0 0 1 [21] .strtab STRTAB
00000000 000f76 0001b3 00 0 0 1 [22] .ARM.attributes ARM_ATTRIBUTES 00000000
001129 000044 00 0 0 1`

It seems that the section name can be arbitrarily chosen (am I right?) If so,
then my questiones are

  1. how to tell which section contains what? (for example, which section contains code and which section contains read only data....). 

  2. How to know the definition of each section, for example how do I know the section "[12] __ARM_grp..debug_" is for what purpose? 

Thanks in advance.

[elf](/questions/tagged/elf "show questions tagged 'elf'")

[share](/q/51923257 "short permalink to this question")|[improve this
question](/posts/51923257/edit)

[edited Aug 20 '18 at 1:54](/posts/51923257/revisions "show all edits to this
post")

heliboy

asked Aug 20 '18 at 1:48

[![](https://www.gravatar.com/avatar/e0f927db8302eec4e97820ed5de1dabe?s=32&d=identicon&r=PG&f=1)](/users/10247657/heliboy)

[heliboy](/users/10247657/heliboy)heliboy

143

add a comment |

##  1 Answer 1

[ active](/questions/51923257/for-elf-file-how-to-tell-which-section-contains-
execution-binary-code?answertab=active#tab-top "Answers with the latest
activity first") [ oldest](/questions/51923257/for-elf-file-how-to-tell-which-
section-contains-execution-binary-code?answertab=oldest#tab-top "Answers in
the order they were provided") [ votes](/questions/51923257/for-elf-file-how-
to-tell-which-section-contains-execution-binary-code?answertab=votes#tab-top
"Answers with the highest score first")

1

As for the first part of your question, when determining what sections contain
code and which sections contain read only data, a good thing to look for is
the section attribute flags.

With the `readelf -S` command, an `X` indicates that the section contains
executable instructions, an `A` indicates that the section occupies memory
during process execution, and a `W` indicates that the section should be
writable.

So in your object file, there is one section, `i.main` that is executable, and
it is also read only. The other sections aren't writable, but not read only
since they aren't in memory at all.

I'm not very familiar with ARM binaries, so I can't really address the other
parts of your question.

[share](/a/51923456 "short permalink to this answer")|[improve this
answer](/posts/51923456/edit)

answered Aug 20 '18 at 2:26

[![](https://i.stack.imgur.com/aqAiW.png?s=32&g=1)](/users/4921099/martin)

[martin](/users/4921099/martin)martin

66721018

  * 1

Also note that in an executable (or shared library), sections are _not
necessary_ , and could be completely stripped, though this isn't common. At
runtime, only _segments_ matter. - [Employed Russian](/users/50617/employed-
russian "126,762 reputation") Aug 20 '18 at 16:51

add a comment |

## Your Answer

Thanks for contributing an answer to Stack Overflow!

  * Please be sure to _answer the question_. Provide details and share your research!

But _avoid_ …

  * Asking for help, clarification, or responding to other answers.
  * Making statements based on opinion; back them up with references or personal experience.

To learn more, see our [tips on writing great answers](/help/how-to-answer).

draft saved

draft discarded

### Sign up or [log
in](/users/login?ssrc=question_page&returnurl=https%3a%2f%2fstackoverflow.com%2fquestions%2f51923257%2ffor-
elf-file-how-to-tell-which-section-contains-execution-binary-code%23new-
answer)

Sign up using Google

Sign up using Facebook

Sign up using Email and Password

### Post as a guest

Name

Email

Required, but never shown

### Post as a guest

Name

Email

Required, but never shown

Post Your Answer  Discard

By clicking "Post Your Answer", you agree to our [terms of
service](https://stackoverflow.com/legal/terms-of-service/public), [privacy
policy](https://stackoverflow.com/legal/privacy-policy) and [cookie
policy](https://stackoverflow.com/legal/cookie-policy)

##  Not the answer you're looking for? Browse other questions tagged
[elf](/questions/tagged/elf "show questions tagged 'elf'") or [ask your own
question](/questions/ask).

asked

|

** 7 months ago **  
  
---|---  
  
viewed

|

**159 times**  
  
active

|

**[7 months ago](?lastactivity "2018-08-20 02:26:19Z")**  
  
#### Related

[17](/q/9226088 "Vote score \(upvotes - downvotes\)")[How are the different
segments like heap, stack, text related to the physical
memory?](/questions/9226088/how-are-the-different-segments-like-heap-stack-
text-related-to-the-physical-me)

[8](/q/9721985 "Vote score \(upvotes - downvotes\)")[How do I merge two binary
executables?](/questions/9721985/how-do-i-merge-two-binary-executables)

[0](/q/10945239 "Vote score \(upvotes - downvotes\)")[Trouble using
Libelf/Elfio libraries : ELF not executable
anymore](/questions/10945239/trouble-using-libelf-elfio-libraries-elf-not-
executable-anymore)

[3](/q/18278803 "Vote score \(upvotes - downvotes\)")[How does ELF file format
defines the stack?](/questions/18278803/how-does-elf-file-format-defines-the-
stack)

[0](/q/29029735 "Vote score \(upvotes - downvotes\)")[Possible to add
executable section/segment to ELF binary?](/questions/29029735/possible-to-
add-executable-section-segment-to-elf-binary)

[7](/q/32437714 "Vote score \(upvotes - downvotes\)")[How to add (and use)
binary data to compiled executable?](/questions/32437714/how-to-add-and-use-
binary-data-to-compiled-executable)

[1](/q/34910726 "Vote score \(upvotes - downvotes\)")[ELF binary make section
unaccessible](/questions/34910726/elf-binary-make-section-unaccessible)

[0](/q/43948784 "Vote score \(upvotes - downvotes\)")[Crafting an ELF file
using linker scripts without zero-initialized blocks between
sections](/questions/43948784/crafting-an-elf-file-using-linker-scripts-
without-zero-initialized-blocks-betwee)

[1](/q/47083090 "Vote score \(upvotes - downvotes\)")[modified elf symbol but
not reflecting in disassembly](/questions/47083090/modified-elf-symbol-but-
not-reflecting-in-disassembly)

[0](/q/48431694 "Vote score \(upvotes - downvotes\)")[Linker (ld) ELF
Questions](/questions/48431694/linker-ld-elf-questions)

####  [ Hot Network Questions ](https://stackexchange.com/questions?tab=hot)

  * [ Mixing PEX brands ](https://diy.stackexchange.com/questions/160408/mixing-pex-brands)
  * [ Electoral considerations aside, what are potential benefits, for the US, of policy changes proposed by the tweet recognizing Golan annexation? ](https://politics.stackexchange.com/questions/39667/electoral-considerations-aside-what-are-potential-benefits-for-the-us-of-poli)
  * [ Can a stoichiometric mixture of oxygen and methane exist as a liquid at standard pressure and some (low) temperature? ](https://chemistry.stackexchange.com/questions/111355/can-a-stoichiometric-mixture-of-oxygen-and-methane-exist-as-a-liquid-at-standard)
  * [ What features enable the Su-25 Frogfoot to operate with such a wide variety of fuels? ](https://aviation.stackexchange.com/questions/61467/what-features-enable-the-su-25-frogfoot-to-operate-with-such-a-wide-variety-of-f)
  * [ How do apertures which seem too large to physically fit work? ](https://photo.stackexchange.com/questions/106099/how-do-apertures-which-seem-too-large-to-physically-fit-work)
  * [ Can I still be respawned if I die by falling off the map? ](https://gaming.stackexchange.com/questions/348072/can-i-still-be-respawned-if-i-die-by-falling-off-the-map)
  * [ How to say when an application is taking the half of your screen on a computer ](https://ell.stackexchange.com/questions/201782/how-to-say-when-an-application-is-taking-the-half-of-your-screen-on-a-computer)
  * [ How do you respond to a colleague from another team when they're wrongly expecting that you'll help them? ](https://workplace.stackexchange.com/questions/132259/how-do-you-respond-to-a-colleague-from-another-team-when-theyre-wrongly-expecti)
  * [ Can a college of swords bard use blade flourish on an OA from dissonant whispers? ](https://rpg.stackexchange.com/questions/143716/can-a-college-of-swords-bard-use-blade-flourish-on-an-oa-from-dissonant-whispers)
  * [ Add big quotation marks inside my colorbox ](https://tex.stackexchange.com/questions/480939/add-big-quotation-marks-inside-my-colorbox)
  * [ What are the advantages of simplicial model categories over non-simplicial ones? ](https://mathoverflow.net/questions/326059/what-are-the-advantages-of-simplicial-model-categories-over-non-simplicial-ones)
  * [ Bridge building with irregular planks ](https://puzzling.stackexchange.com/questions/80933/bridge-building-with-irregular-planks)
  * [ How much character growth crosses the line into breaking the character ](https://writing.stackexchange.com/questions/43927/how-much-character-growth-crosses-the-line-into-breaking-the-character)
  * [ 15% tax on $7.5k earnings. Is that right? ](https://money.stackexchange.com/questions/106787/15-tax-on-7-5k-earnings-is-that-right)
  * [ Why should universal income be universal? ](https://politics.stackexchange.com/questions/39639/why-should-universal-income-be-universal)
  * [ What should you do if you miss a job interview (deliberately)? ](https://workplace.stackexchange.com/questions/132273/what-should-you-do-if-you-miss-a-job-interview-deliberately)
  * [ How to cover method return statement in Apex Class? ](https://salesforce.stackexchange.com/questions/254931/how-to-cover-method-return-statement-in-apex-class)
  * [ How could a planet have erratic days? ](https://worldbuilding.stackexchange.com/questions/142019/how-could-a-planet-have-erratic-days)
  * [ Why Shazam when there is already Superman? ](https://movies.stackexchange.com/questions/97904/why-shazam-when-there-is-already-superman)
  * [ Calculating total slots ](https://codegolf.stackexchange.com/questions/182010/calculating-total-slots)
  * [ What does "Scientists rise up against statistical significance" mean? (Comment in Nature) ](https://stats.stackexchange.com/questions/398646/what-does-scientists-rise-up-against-statistical-significance-mean-comment-i)
  * [ Does the UK parliament need to pass secondary legislation to accept the Article 50 extension ](https://politics.stackexchange.com/questions/39683/does-the-uk-parliament-need-to-pass-secondary-legislation-to-accept-the-article)
  * [ Can I say "fingers" when referring to toes? ](https://ell.stackexchange.com/questions/201499/can-i-say-fingers-when-referring-to-toes)
  * [ How does a computer interpret real numbers? ](https://cs.stackexchange.com/questions/105923/how-does-a-computer-interpret-real-numbers)

more hot questions

[ question feed ](/feeds/question/51923257 "feed of this question and its
answers")

![](/posts/51923257/ivc/dcb3)

[](https://stackoverflow.com)

##### [Stack Overflow](https://stackoverflow.com)

  * [Questions](/questions)
  * [Jobs](https://stackoverflow.com/jobs)
  * [Developer Jobs Directory](https://stackoverflow.com/jobs/directory/developer-jobs)
  * [Salary Calculator](https://stackoverflow.com/jobs/salary)
  * [Help](/help)
  * Mobile

##### [Products](https://www.stackoverflowbusiness.com)

  * [Teams](https://stackoverflow.com/teams)
  * [Talent](https://www.stackoverflowbusiness.com/talent)
  * [Advertising](https://www.stackoverflowbusiness.com/advertising)
  * [Enterprise](https://stackoverflow.com/enterprise)

##### [Company](https://stackoverflow.com/company/about)

  * [About](https://stackoverflow.com/company/about)
  * [Press](https://stackoverflow.com/company/press)
  * [Work Here](https://stackoverflow.com/company/work-here)
  * [Legal](https://stackoverflow.com/legal)
  * [Privacy Policy](https://stackoverflow.com/legal/privacy-policy)
  * [Contact Us](https://stackoverflow.com/company/contact)

##### [Stack Exchange  
Network](https://stackexchange.com)

  * Technology
  * Life / Arts
  * Culture / Recreation
  * Science
  * Other

  * [Stack Overflow](https://stackoverflow.com "professional and enthusiast programmers")
  * [Server Fault](https://serverfault.com "system and network administrators")
  * [Super User](https://superuser.com "computer enthusiasts and power users")
  * [Web Applications](https://webapps.stackexchange.com "power users of web applications")
  * [Ask Ubuntu](https://askubuntu.com "Ubuntu users and developers")
  * [Webmasters](https://webmasters.stackexchange.com "pro webmasters")
  * [Game Development](https://gamedev.stackexchange.com "professional and independent game developers")

  * [TeX - LaTeX](https://tex.stackexchange.com "users of TeX, LaTeX, ConTeXt, and related typesetting systems")
  * [Software Engineering](https://softwareengineering.stackexchange.com "professionals, academics, and students working within the systems development life cycle")
  * [Unix & Linux](https://unix.stackexchange.com "users of Linux, FreeBSD and other Un*x-like operating systems")
  * [Ask Different (Apple)](https://apple.stackexchange.com "power users of Apple hardware and software")
  * [WordPress Development](https://wordpress.stackexchange.com "WordPress developers and administrators")
  * [Geographic Information Systems](https://gis.stackexchange.com "cartographers, geographers and GIS professionals")
  * [Electrical Engineering](https://electronics.stackexchange.com "electronics and electrical engineering professionals, students, and enthusiasts")

  * [Android Enthusiasts](https://android.stackexchange.com "enthusiasts and power users of the Android operating system")
  * [Information Security](https://security.stackexchange.com "information security professionals")
  * [Database Administrators](https://dba.stackexchange.com "database professionals who wish to improve their database skills and learn from others in the community")
  * [Drupal Answers](https://drupal.stackexchange.com "Drupal developers and administrators")
  * [SharePoint](https://sharepoint.stackexchange.com "SharePoint enthusiasts")
  * [User Experience](https://ux.stackexchange.com "user experience researchers and experts")
  * [Mathematica](https://mathematica.stackexchange.com "users of Wolfram Mathematica")

  * [Salesforce](https://salesforce.stackexchange.com "Salesforce administrators, implementation experts, developers and anybody in-between")
  * [ExpressionEngine® Answers](https://expressionengine.stackexchange.com "administrators, end users, developers and designers for ExpressionEngine® CMS")
  * [Stack Overflow em Portugues](https://pt.stackoverflow.com "programadores profissionais e entusiastas")
  * [Blender](https://blender.stackexchange.com "people who use Blender to create 3D graphics, animations, or games")
  * [Network Engineering](https://networkengineering.stackexchange.com "network engineers")
  * [Cryptography](https://crypto.stackexchange.com "software developers, mathematicians and others interested in cryptography")
  * [Code Review](https://codereview.stackexchange.com "peer programmer code reviews")

  * [Magento](https://magento.stackexchange.com "users of the Magento e-Commerce platform")
  * [Software Recommendations](https://softwarerecs.stackexchange.com "people seeking specific software recommendations")
  * [Signal Processing](https://dsp.stackexchange.com "practitioners of the art and science of signal, image and video processing")
  * [Emacs](https://emacs.stackexchange.com "those using, extending or developing Emacs")
  * [Raspberry Pi](https://raspberrypi.stackexchange.com "users and developers of hardware and software for Raspberry Pi")
  * [Stack Overflow на русском](https://ru.stackoverflow.com "программистов")
  * [Programming Puzzles & Code Golf](https://codegolf.stackexchange.com "programming puzzle enthusiasts and code golfers")

  * [Stack Overflow en español](https://es.stackoverflow.com "programadores y profesionales de la informática")
  * [Ethereum](https://ethereum.stackexchange.com "users of Ethereum, the decentralized application platform and smart contract enabled blockchain")
  * [Data Science](https://datascience.stackexchange.com "Data science professionals, Machine Learning specialists, and those interested in learning more about the field")
  * [Arduino](https://arduino.stackexchange.com "developers of open-source hardware and software that is compatible with Arduino")
  * [Bitcoin](https://bitcoin.stackexchange.com "Bitcoin crypto-currency enthusiasts")
  * [ **more (31)** ](https://stackexchange.com/sites#technology)

  * [Photography](https://photo.stackexchange.com "professional, enthusiast and amateur photographers")
  * [Science Fiction & Fantasy](https://scifi.stackexchange.com "science fiction and fantasy enthusiasts")
  * [Graphic Design](https://graphicdesign.stackexchange.com "Graphic Design professionals, students, and enthusiasts")
  * [Movies & TV](https://movies.stackexchange.com "movie and tv enthusiasts")
  * [Music: Practice & Theory](https://music.stackexchange.com "musicians, students, and enthusiasts")
  * [Worldbuilding](https://worldbuilding.stackexchange.com "writers/artists using science, geography and culture to construct imaginary worlds and settings")
  * [Seasoned Advice (cooking)](https://cooking.stackexchange.com "professional and amateur chefs")

  * [Home Improvement](https://diy.stackexchange.com "contractors and serious DIYers")
  * [Personal Finance & Money](https://money.stackexchange.com "people who want to be financially literate")
  * [Academia](https://academia.stackexchange.com "academics and those enrolled in higher education")
  * [Law](https://law.stackexchange.com "legal professionals, students, and others with experience or interest in law")
  * [ **more (15)** ](https://stackexchange.com/sites#lifearts)

  * [English Language & Usage](https://english.stackexchange.com "linguists, etymologists, and serious English language enthusiasts")
  * [Skeptics](https://skeptics.stackexchange.com "scientific skepticism")
  * [Mi Yodeya (Judaism)](https://judaism.stackexchange.com "those who base their lives on Jewish law and tradition and anyone interested in learning more")
  * [Travel](https://travel.stackexchange.com "road warriors and seasoned travelers")
  * [Christianity](https://christianity.stackexchange.com "committed Christians, experts in Christianity and those interested in learning more")
  * [English Language Learners](https://ell.stackexchange.com "speakers of other languages learning English")
  * [Japanese Language](https://japanese.stackexchange.com "students, teachers, and linguists wanting to discuss the finer points of the Japanese language")

  * [Arqade (gaming)](https://gaming.stackexchange.com "passionate videogamers on all platforms")
  * [Bicycles](https://bicycles.stackexchange.com "people who build and repair bicycles, people who train cycling, or commute on bicycles")
  * [Role-playing Games](https://rpg.stackexchange.com "gamemasters and players of tabletop, paper-and-pencil role-playing games")
  * [Anime & Manga](https://anime.stackexchange.com "anime and manga fans")
  * [Puzzling](https://puzzling.stackexchange.com "those who create, solve, and study puzzles")
  * [Motor Vehicle Maintenance & Repair](https://mechanics.stackexchange.com "mechanics and DIY enthusiast owners of cars, trucks, and motorcycles")
  * [ **more (33)** ](https://stackexchange.com/sites#culturerecreation)

  * [MathOverflow](https://mathoverflow.net "professional mathematicians")
  * [Mathematics](https://math.stackexchange.com "people studying math at any level and professionals in related fields")
  * [Cross Validated (stats)](https://stats.stackexchange.com "people interested in statistics, machine learning, data analysis, data mining, and data visualization")
  * [Theoretical Computer Science](https://cstheory.stackexchange.com "theoretical computer scientists and researchers in related fields")
  * [Physics](https://physics.stackexchange.com "active researchers, academics and students of physics")
  * [Chemistry](https://chemistry.stackexchange.com "scientists, academics, teachers, and students in the field of chemistry")
  * [Biology](https://biology.stackexchange.com "biology researchers, academics, and students")

  * [Computer Science](https://cs.stackexchange.com "students, researchers and practitioners of computer science")
  * [Philosophy](https://philosophy.stackexchange.com "those interested in the study of the fundamental nature of knowledge, reality, and existence")
  * [ **more (10)** ](https://stackexchange.com/sites#science)

  * [Meta Stack Exchange](https://meta.stackexchange.com "meta-discussion of the Stack Exchange family of Q&A websites")
  * [Stack Apps](https://stackapps.com "apps, scripts, and development with the Stack Exchange API")
  * [API](https://api.stackexchange.com "programmatic interaction with Stack Exchange sites")
  * [Data](https://data.stackexchange.com "querying Stack Exchange data using SQL")

  * [Blog](https://stackoverflow.blog?blb=1)
  * [Facebook](https://www.facebook.com/officialstackoverflow/)
  * [Twitter](https://twitter.com/stackoverflow)
  * [LinkedIn](https://linkedin.com/company/stack-overflow)

site design / logo  (C) 2019 Stack Exchange Inc; user contributions licensed
under [cc by-sa 3.0](https://creativecommons.org/licenses/by-sa/3.0/) with
[attribution required](https://stackoverflow.blog/2009/06/25/attribution-
required/). rev 2019.3.22.33110

Stack Overflow works best with JavaScript enabled
![](https://pixel.quantserve.com/pixel/p-c1rF4kxgLUzNc.gif)

