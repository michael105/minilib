<#> Stack Overflow <https://stackoverflow.com/>

 1.

    <#>
 2.

    <https://stackexchange.com/users/?tab=inbox>
 3.

    <https://stackexchange.com/users/?tab=reputation>
 4.

    <#>
 5.

    <https://stackexchange.com/>
 6. Log In
    <https://stackoverflow.com/users/login?ssrc=head&returnurl=https%3a%2f%2fstackoverflow.com%2fquestions%2f51923257%2ffor-elf-file-how-to-tell-which-section-contains-execution-binary-code>
    Sign Up
    <https://stackoverflow.com/users/signup?ssrc=head&returnurl=%2fusers%2fstory%2fcurrent>

 7.


          current community <https://stackoverflow.com/>

      *
        Stack Overflow <https://stackoverflow.com/>
        help <https://stackoverflow.com/help> chat
        <https://chat.stackoverflow.com/>
      *
        Meta Stack Overflow <https://meta.stackoverflow.com/>


          your communities

    Sign up
    <https://stackoverflow.com/users/signup?ssrc=site_switcher&returnurl=%2fusers%2fstory%2fcurrent>
    or log in
    <https://stackoverflow.com/users/login?ssrc=site_switcher&returnurl=https%3a%2f%2fstackoverflow.com%2fquestions%2f51923257%2ffor-elf-file-how-to-tell-which-section-contains-execution-binary-code>
    to customize your list.


          more stack exchange communities <https://stackexchange.com/sites>

    company blog <https://stackoverflow.blog/>
      * Tour Start here for a quick overview of the site
        <https://stackoverflow.com/tour>
      * Help Center Detailed answers to any questions you might have
        <https://stackoverflow.com/help>
      * Meta Discuss the workings and policies of this site
        <https://meta.stackoverflow.com/>
      * About Us Learn more about Stack Overflow the company
        <https://stackoverflow.com/company/about>
      * Business Learn more about hiring developers or posting ads with
        us <https://www.stackoverflowbusiness.com/?ref=topbar_help>

By using our site, you acknowledge that you have read and understand our
Cookie Policy <https://stackoverflow.com/legal/cookie-policy>, Privacy
Policy <https://stackoverflow.com/legal/privacy-policy>, and our Terms
of Service <https://stackoverflow.com/legal/terms-of-service/public>.

 1.
 2. Home <https://stackoverflow.com/>
 3.
     1. Public
     2.

        Stack Overflow <https://stackoverflow.com/questions>
     3. Tags <https://stackoverflow.com/tags>
     4. Users <https://stackoverflow.com/users>
     5. Jobs <https://stackoverflow.com/jobs?med=site-ui&ref=jobs-tab>
 4.
     1.
        *Teams

        * Q&A for work Learn More <https://stackoverflow.com/teams>


  For ELF file, how to tell which section contains execution binary
  code?
  <https://stackoverflow.com/questions/51923257/for-elf-file-how-to-tell-which-section-contains-execution-binary-code>

Ask Question <https://stackoverflow.com/questions/ask>

3

I am studying ELF and having a doubt for a while. I tried to search for
the answer but in vain. I'd apprciated if somebody could give me the
answer or guide me to the place to find an answer.

Almost all the documents I read about ELF said .text section contains
executable binary code (and .data contains data....). However, when I
used readelf to see the sections contain in an obj file, I saw no .text
section but a section called i.main which contains the executable code
(from the code contained in this section I found the machine code). The
following shows the sections parsed by readelf

|Section Headers:
    [Nr] Name              Type            Addr     Off    Size   ES Flg Lk Inf Al
    [ 0]                   NULL            00000000 000000 000000 00      0   0  0
    [ 1] i.main            PROGBITS        00000000 000034 00000a 00  AX  0   0  2
    [ 2] .arm_vfe_header   PROGBITS        00000000 000040 000004 00      0   0  4
    [ 3] .comment          PROGBITS        00000000 000044 0001c6 00      0   0  1
    [ 4] .debug_frame      PROGBITS        00000000 00020a 00003c 00      0   0  1
    [ 5] .debug_info       PROGBITS        00000000 000246 000088 00      0   0  1
    [ 6] .debug_info       PROGBITS        00000000 0002ce 0000dc 00      0   0  1
    [ 7] .debug_line       PROGBITS        00000000 0003aa 000030 00      0   0  1
    [ 8] .debug_line       PROGBITS        00000000 0003da 000044 00      0   0  1
    [ 9] .debug_loc        PROGBITS        00000000 00041e 000014 00      0   0  1
    [10] .debug_macinfo    PROGBITS        00000000 000432 000308 00      0   0  1
    [11] .debug_pubnames   PROGBITS        00000000 00073a 00001b 00      0   0  1
    [12] __ARM_grp..debug_ GROUP           00000000 000758 000008 04     14  14  4
    [13] .debug_abbrev     PROGBITS        00000000 000760 0005a4 00   G  0   0  1
    [14] .symtab           SYMTAB          00000000 000d04 000110 10     21  13  4
    [15] .rel.debug_frame  REL             00000000 000e14 000010 08     14   4  4
    [16] .rel.debug_info   REL             00000000 000e24 000018 08     14   5  4
    [17] .rel.debug_info   REL             00000000 000e3c 000038 08     14   6  4
    [18] .rel.debug_line   REL             00000000 000e74 000008 08     14   8  4
    [19] .rel.debug_pubnam REL             00000000 000e7c 000008 08     14  11  4
    [20] .shstrtab         STRTAB          00000000 000e84 0000f2 00      0   0  1
    [21] .strtab           STRTAB          00000000 000f76 0001b3 00      0   0  1
    [22] .ARM.attributes   ARM_ATTRIBUTES  00000000 001129 000044 00      0   0  1|

It seems that the section name can be arbitrarily chosen (am I right?)
If so, then my questiones are

 1.

    how to tell which section contains what? (for example, which section
    contains code and which section contains read only data....).

 2.

    How to know the definition of each section, for example how do I
    know the section "[12] __ARM_grp..debug_" is for what purpose?

Thanks in advance.

elf <https://stackoverflow.com/questions/tagged/elf>
share <https://stackoverflow.com/q/51923257>|improve this question
<https://stackoverflow.com/posts/51923257/edit>
edited Aug 20 '18 at 1:54
<https://stackoverflow.com/posts/51923257/revisions>
heliboy
asked Aug 20 '18 at 1:48
<https://stackoverflow.com/users/10247657/heliboy>
heliboy <https://stackoverflow.com/users/10247657/heliboy>heliboy
143

add a comment |  <#>


    1 Answer 1

active
<https://stackoverflow.com/questions/51923257/for-elf-file-how-to-tell-which-section-contains-execution-binary-code?answertab=active#tab-top>
oldest
<https://stackoverflow.com/questions/51923257/for-elf-file-how-to-tell-which-section-contains-execution-binary-code?answertab=oldest#tab-top>
votes
<https://stackoverflow.com/questions/51923257/for-elf-file-how-to-tell-which-section-contains-execution-binary-code?answertab=votes#tab-top>


1

As for the first part of your question, when determining what sections
contain code and which sections contain read only data, a good thing to
look for is the section attribute flags.

With the |readelf -S| command, an |X| indicates that the section contains executable instructions, an |A| indicates that the section occupies memory during process execution,
and a |W| indicates that the section should be writable.

So in your object file, there is one section, |i.main| that is executable, and it is also read only. The other sections aren't
writable, but not read only since they aren't in memory at all.

I'm not very familiar with ARM binaries, so I can't really address the
other parts of your question.

share <https://stackoverflow.com/a/51923456>|improve this answer
<https://stackoverflow.com/posts/51923456/edit>
answered Aug 20 '18 at 2:26
<https://stackoverflow.com/users/4921099/martin>
martin <https://stackoverflow.com/users/4921099/martin>martin
66721018

  *
    1
    Also note that in an executable (or shared library), sections are
    /not necessary/, and could be completely stripped, though this isn't
    common. At runtime, only /segments/ matter. – Employed Russian
    <https://stackoverflow.com/users/50617/employed-russian> Aug 20 '18
    at 16:51 <#comment90820596_51923456>

add a comment |  <#>


    Your Answer

  *
  *
  *
  *
  *
  *
  *
  *
  *
  *
  *
  *
  *
  *
  *
*

Thanks for contributing an answer to Stack Overflow!

  * Please be sure to /answer the question/. Provide details and share
    your research!

But /avoid/ …

  * Asking for help, clarification, or responding to other answers.
  * Making statements based on opinion; back them up with references or
    personal experience.

To learn more, see our tips on writing great answers
<https://stackoverflow.com/help/how-to-answer>.

draft saved
draft discarded


      Sign up or log in
      <https://stackoverflow.com/users/login?ssrc=question_page&returnurl=https%3a%2f%2fstackoverflow.com%2fquestions%2f51923257%2ffor-elf-file-how-to-tell-which-section-contains-execution-binary-code%23new-answer>

Sign up using Google
Sign up using Facebook
Sign up using Email and Password


      Post as a guest

Name

Email

Required, but never shown

Post Your Answer Discard

By clicking "Post Your Answer", you agree to our terms of service
<https://stackoverflow.com/legal/terms-of-service/public>, privacy
policy <https://stackoverflow.com/legal/privacy-policy> and cookie
policy <https://stackoverflow.com/legal/cookie-policy>


    Not the answer you're looking for? Browse other questions tagged elf
    <https://stackoverflow.com/questions/tagged/elf> or ask your own
    question <https://stackoverflow.com/questions/ask>.

asked

	

*7 months ago *

viewed

	

*157 times*

active

	

*7 months ago
<https://stackoverflow.com/questions/51923257/for-elf-file-how-to-tell-which-section-contains-execution-binary-code?lastactivity>*

<https://stackoverflow.com/jobs/companies/swiss-life-deutschland>
Swiss Life Deutschland


    Swiss Life Deutschland

Finance, Insurance

  *
    *Senior DevOps Engineer Cloud/On premise (m/w)*
    München, Deutschland
    linuxcloud
     <https://stackoverflow.com/jobs/207989/senior-devops-engineer-cloud-on-premise-m-w-swiss-life-deutschland>
  *
    *Senior Software-Entwickler (m/w) C++ / Java für Vertriebssysteme*
    München, Deutschland
    c++java
     <https://stackoverflow.com/jobs/208737/senior-software-entwickler-m-w-c-plus-plus-java-f%C3%BCr-swiss-life-deutschland>
  *
    *(Senior) Software-Entwickler (m/w) C/Linux für Versicherungssysteme*
    München, Deutschland
    linuxc
     <https://stackoverflow.com/jobs/208736/senior-software-entwickler-m-w-c-linux-f%C3%BCr-swiss-life-deutschland> 

View all 10 job openings!
<https://stackoverflow.com/jobs/companies/swiss-life-deutschland>
<https://stackoverflow.com/jobs/companies/it-economics>
it-economics


    it-economics

  *
    *Developer (m/w/d)*
    München, Deutschland€50k - €80k
    javascriptjava
     <https://stackoverflow.com/jobs/169304/developer-m-w-d-it-economics>
  *
    *Software Architect (m/w/d) Karlsruhe*
    Karlsruhe, Deutschland€80k - €100k
    javascriptjava
     <https://stackoverflow.com/jobs/242460/software-architect-m-w-d-karlsruhe-it-economics>
  *
    *Developer (m/w/d)*
    Münster, Deutschland€50k - €80k
    javascriptjava
     <https://stackoverflow.com/jobs/163749/developer-m-w-d-it-economics> 

View all 3 job openings!
<https://stackoverflow.com/jobs/companies/it-economics>


        Related

17
 <https://stackoverflow.com/q/9226088?rq=1>How are the different
segments like heap, stack, text related to the physical memory?
<https://stackoverflow.com/questions/9226088/how-are-the-different-segments-like-heap-stack-text-related-to-the-physical-me?rq=1>
8
 <https://stackoverflow.com/q/9721985?rq=1>How do I merge two binary
executables?
<https://stackoverflow.com/questions/9721985/how-do-i-merge-two-binary-executables?rq=1>
0
 <https://stackoverflow.com/q/10945239?rq=1>Trouble using Libelf/Elfio
libraries : ELF not executable anymore
<https://stackoverflow.com/questions/10945239/trouble-using-libelf-elfio-libraries-elf-not-executable-anymore?rq=1>
3
 <https://stackoverflow.com/q/18278803?rq=1>How does ELF file format
defines the stack?
<https://stackoverflow.com/questions/18278803/how-does-elf-file-format-defines-the-stack?rq=1>
0
 <https://stackoverflow.com/q/29029735?rq=1>Possible to add executable
section/segment to ELF binary?
<https://stackoverflow.com/questions/29029735/possible-to-add-executable-section-segment-to-elf-binary?rq=1>
7
 <https://stackoverflow.com/q/32437714?rq=1>How to add (and use) binary
data to compiled executable?
<https://stackoverflow.com/questions/32437714/how-to-add-and-use-binary-data-to-compiled-executable?rq=1>
1
 <https://stackoverflow.com/q/34910726?rq=1>ELF binary make section
unaccessible
<https://stackoverflow.com/questions/34910726/elf-binary-make-section-unaccessible?rq=1>
0
 <https://stackoverflow.com/q/43948784?rq=1>Crafting an ELF file using
linker scripts without zero-initialized blocks between sections
<https://stackoverflow.com/questions/43948784/crafting-an-elf-file-using-linker-scripts-without-zero-initialized-blocks-betwee?rq=1>
1
 <https://stackoverflow.com/q/47083090?rq=1>modified elf symbol but not
reflecting in disassembly
<https://stackoverflow.com/questions/47083090/modified-elf-symbol-but-not-reflecting-in-disassembly?rq=1>
0
 <https://stackoverflow.com/q/48431694?rq=1>Linker (ld) ELF Questions
<https://stackoverflow.com/questions/48431694/linker-ld-elf-questions?rq=1>


        Hot Network Questions <https://stackexchange.com/questions?tab=hot>

  *
    How to cover method return statement in Apex Class?
    <https://salesforce.stackexchange.com/questions/254931/how-to-cover-method-return-statement-in-apex-class>

  *
    What is going on with 'gets(stdin)' on the site coderbyte?
    <https://stackoverflow.com/questions/55269252/what-is-going-on-with-getsstdin-on-the-site-coderbyte>

  *
    What if you are holding an Iron Flask with a demon inside and walk
    into Antimagic Field?
    <https://rpg.stackexchange.com/questions/143705/what-if-you-are-holding-an-iron-flask-with-a-demon-inside-and-walk-into-antimagi>

  *
    What reason has the US given for (Trump's tweet) recognising Israel
    has sovereignty over the Golan?
    <https://politics.stackexchange.com/questions/39667/what-reason-has-the-us-given-for-trumps-tweet-recognising-israel-has-sovereig>

  *
    How do you respond to a colleague from another team when they're
    wrongly expecting that you'll help them?
    <https://workplace.stackexchange.com/questions/132259/how-do-you-respond-to-a-colleague-from-another-team-when-theyre-wrongly-expecti>

  *
    Open a doc from terminal, but not by its name
    <https://askubuntu.com/questions/1127755/open-a-doc-from-terminal-but-not-by-its-name>

  *
    Why does AES have exactly 10 rounds for a 128-bit key, 12 for 192
    bits and 14 for a 256-bit key size?
    <https://crypto.stackexchange.com/questions/68199/why-does-aes-have-exactly-10-rounds-for-a-128-bit-key-12-for-192-bits-and-14-fo>

  *
    Has any country ever had 2 former presidents in jail simultaneously?
    <https://history.stackexchange.com/questions/51723/has-any-country-ever-had-2-former-presidents-in-jail-simultaneously>

  *
    How to get directions in deep space?
    <https://worldbuilding.stackexchange.com/questions/141867/how-to-get-directions-in-deep-space>

  *
    What features enable the Su-25 Frogfoot to operate with such a wide
    variety of fuels?
    <https://aviation.stackexchange.com/questions/61467/what-features-enable-the-su-25-frogfoot-to-operate-with-such-a-wide-variety-of-f>

  *
    Can a stoichiometric mixture of oxygen and methane exist as a liquid
    at standard pressure and some (low) temperature?
    <https://chemistry.stackexchange.com/questions/111355/can-a-stoichiometric-mixture-of-oxygen-and-methane-exist-as-a-liquid-at-standard>

  *
    How should I address a possible mistake to co-authors in a submitted
    paper
    <https://academia.stackexchange.com/questions/126879/how-should-i-address-a-possible-mistake-to-co-authors-in-a-submitted-paper>

  *
    Is it possible to implement a neural network that computes y = x^2?
    <https://datascience.stackexchange.com/questions/47787/is-it-possible-to-implement-a-neural-network-that-computes-y-x2>

  *
    Hash table solution to twoSum
    <https://codereview.stackexchange.com/questions/215975/hash-table-solution-to-twosum>

  *
    Angel of Condemnation - Exile creature with second ability
    <https://boardgames.stackexchange.com/questions/45617/angel-of-condemnation-exile-creature-with-second-ability>

  *
    Pre-mixing cryogenic fuels and using only one fuel tank
    <https://space.stackexchange.com/questions/34973/pre-mixing-cryogenic-fuels-and-using-only-one-fuel-tank>

  *
    How to copy file from a list to a new folder?
    <https://askubuntu.com/questions/1127773/how-to-copy-file-from-a-list-to-a-new-folder>

  *
    How much character growth crosses the line into breaking the
    character
    <https://writing.stackexchange.com/questions/43927/how-much-character-growth-crosses-the-line-into-breaking-the-character>

  *
    Isn't the "if" redundant here?
    <https://stackoverflow.com/questions/55300081/isnt-the-if-redundant-here>

  *
    How to align my equation to left?
    <https://tex.stackexchange.com/questions/480865/how-to-align-my-equation-to-left>

  *
    The Digit Triangles
    <https://codegolf.stackexchange.com/questions/181885/the-digit-triangles>

  *
    The IT department bottlenecks progress, how should I handle this?
    <https://academia.stackexchange.com/questions/126826/the-it-department-bottlenecks-progress-how-should-i-handle-this>

  *
    Why Shazam when there is already Superman?
    <https://movies.stackexchange.com/questions/97904/why-shazam-when-there-is-already-superman>

  *
    What is the highest possible scrabble score for placing a single
    tile
    <https://puzzling.stackexchange.com/questions/80897/what-is-the-highest-possible-scrabble-score-for-placing-a-single-tile>


question feed <https://stackoverflow.com/feeds/question/51923257>
<https://stackoverflow.com/>


          Stack Overflow <https://stackoverflow.com/>

  * Questions <https://stackoverflow.com/questions>
  * Jobs <https://stackoverflow.com/jobs>
  * Developer Jobs Directory
    <https://stackoverflow.com/jobs/directory/developer-jobs>
  * Salary Calculator <https://stackoverflow.com/jobs/salary>
  * Help <https://stackoverflow.com/help>
  * Mobile
  * Disable Responsiveness


          Products <https://www.stackoverflowbusiness.com/>

  * Teams <https://stackoverflow.com/teams>
  * Talent <https://www.stackoverflowbusiness.com/talent>
  * Advertising <https://www.stackoverflowbusiness.com/advertising>
  * Enterprise <https://stackoverflow.com/enterprise>


          Company <https://stackoverflow.com/company/about>

  * About <https://stackoverflow.com/company/about>
  * Press <https://stackoverflow.com/company/press>
  * Work Here <https://stackoverflow.com/company/work-here>
  * Legal <https://stackoverflow.com/legal>
  * Privacy Policy <https://stackoverflow.com/legal/privacy-policy>
  * Contact Us <https://stackoverflow.com/company/contact>

<#>


          Stack Exchange
          Network <https://stackexchange.com/>

  * Technology <#>
  * Life / Arts <#>
  * Culture / Recreation <#>
  * Science <#>
  * Other <#>

  * Stack Overflow <https://stackoverflow.com/>
  * Server Fault <https://serverfault.com/>
  * Super User <https://superuser.com/>
  * Web Applications <https://webapps.stackexchange.com/>
  * Ask Ubuntu <https://askubuntu.com/>
  * Webmasters <https://webmasters.stackexchange.com/>
  * Game Development <https://gamedev.stackexchange.com/>

  * TeX - LaTeX <https://tex.stackexchange.com/>
  * Software Engineering <https://softwareengineering.stackexchange.com/>
  * Unix & Linux <https://unix.stackexchange.com/>
  * Ask Different (Apple) <https://apple.stackexchange.com/>
  * WordPress Development <https://wordpress.stackexchange.com/>
  * Geographic Information Systems <https://gis.stackexchange.com/>
  * Electrical Engineering <https://electronics.stackexchange.com/>

  * Android Enthusiasts <https://android.stackexchange.com/>
  * Information Security <https://security.stackexchange.com/>
  * Database Administrators <https://dba.stackexchange.com/>
  * Drupal Answers <https://drupal.stackexchange.com/>
  * SharePoint <https://sharepoint.stackexchange.com/>
  * User Experience <https://ux.stackexchange.com/>
  * Mathematica <https://mathematica.stackexchange.com/>

  * Salesforce <https://salesforce.stackexchange.com/>
  * ExpressionEngine® Answers <https://expressionengine.stackexchange.com/>
  * Stack Overflow em Português <https://pt.stackoverflow.com/>
  * Blender <https://blender.stackexchange.com/>
  * Network Engineering <https://networkengineering.stackexchange.com/>
  * Cryptography <https://crypto.stackexchange.com/>
  * Code Review <https://codereview.stackexchange.com/>

  * Magento <https://magento.stackexchange.com/>
  * Software Recommendations <https://softwarerecs.stackexchange.com/>
  * Signal Processing <https://dsp.stackexchange.com/>
  * Emacs <https://emacs.stackexchange.com/>
  * Raspberry Pi <https://raspberrypi.stackexchange.com/>
  * Stack Overflow на русском <https://ru.stackoverflow.com/>
  * Programming Puzzles & Code Golf <https://codegolf.stackexchange.com/>

  * Stack Overflow en español <https://es.stackoverflow.com/>
  * Ethereum <https://ethereum.stackexchange.com/>
  * Data Science <https://datascience.stackexchange.com/>
  * Arduino <https://arduino.stackexchange.com/>
  * Bitcoin <https://bitcoin.stackexchange.com/>
  * *more (31) * <https://stackexchange.com/sites#technology>

  * Photography <https://photo.stackexchange.com/>
  * Science Fiction & Fantasy <https://scifi.stackexchange.com/>
  * Graphic Design <https://graphicdesign.stackexchange.com/>
  * Movies & TV <https://movies.stackexchange.com/>
  * Music: Practice & Theory <https://music.stackexchange.com/>
  * Worldbuilding <https://worldbuilding.stackexchange.com/>
  * Seasoned Advice (cooking) <https://cooking.stackexchange.com/>

  * Home Improvement <https://diy.stackexchange.com/>
  * Personal Finance & Money <https://money.stackexchange.com/>
  * Academia <https://academia.stackexchange.com/>
  * Law <https://law.stackexchange.com/>
  * *more (15) * <https://stackexchange.com/sites#lifearts>

  * English Language & Usage <https://english.stackexchange.com/>
  * Skeptics <https://skeptics.stackexchange.com/>
  * Mi Yodeya (Judaism) <https://judaism.stackexchange.com/>
  * Travel <https://travel.stackexchange.com/>
  * Christianity <https://christianity.stackexchange.com/>
  * English Language Learners <https://ell.stackexchange.com/>
  * Japanese Language <https://japanese.stackexchange.com/>

  * Arqade (gaming) <https://gaming.stackexchange.com/>
  * Bicycles <https://bicycles.stackexchange.com/>
  * Role-playing Games <https://rpg.stackexchange.com/>
  * Anime & Manga <https://anime.stackexchange.com/>
  * Puzzling <https://puzzling.stackexchange.com/>
  * Motor Vehicle Maintenance & Repair
    <https://mechanics.stackexchange.com/>
  * *more (33) * <https://stackexchange.com/sites#culturerecreation>

  * MathOverflow <https://mathoverflow.net/>
  * Mathematics <https://math.stackexchange.com/>
  * Cross Validated (stats) <https://stats.stackexchange.com/>
  * Theoretical Computer Science <https://cstheory.stackexchange.com/>
  * Physics <https://physics.stackexchange.com/>
  * Chemistry <https://chemistry.stackexchange.com/>
  * Biology <https://biology.stackexchange.com/>

  * Computer Science <https://cs.stackexchange.com/>
  * Philosophy <https://philosophy.stackexchange.com/>
  * *more (10) * <https://stackexchange.com/sites#science>

  * Meta Stack Exchange <https://meta.stackexchange.com/>
  * Stack Apps <https://stackapps.com/>
  * API <https://api.stackexchange.com/>
  * Data <https://data.stackexchange.com/>

  * Blog <https://stackoverflow.blog/?blb=1>
  * Facebook <https://www.facebook.com/officialstackoverflow/>
  * Twitter <https://twitter.com/stackoverflow>
  * LinkedIn <https://linkedin.com/company/stack-overflow>

site design / logo © 2019 Stack Exchange Inc; user contributions
licensed under cc by-sa 3.0
<https://creativecommons.org/licenses/by-sa/3.0/> with attribution
required <https://stackoverflow.blog/2009/06/25/attribution-required/>.
rev 2019.3.22.33110

 
