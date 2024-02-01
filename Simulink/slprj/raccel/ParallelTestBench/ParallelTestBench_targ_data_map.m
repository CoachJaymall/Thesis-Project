    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 2;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (rtP)
        ;%
            section.nData     = 132;
            section.data(132)  = dumData; %prealloc

                    ;% rtP.BLDC_B
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.DatasheetBattery_BattCapInit
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.DatasheetBattery_BattChargeMax
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% rtP.DatasheetBattery_BattTempBp
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% rtP.DatasheetBattery_CapLUTBp
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 10;

                    ;% rtP.DatasheetBattery_CapSOCBp
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 111;

                    ;% rtP.DatasheetBattery_Em
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 117;

                    ;% rtP.BLDC_F
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 218;

                    ;% rtP.BLDC_Id_init
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 219;

                    ;% rtP.BLDC_Iq_init
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 220;

                    ;% rtP.BLDC_J
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 221;

                    ;% rtP.BLDC_Lambda
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 222;

                    ;% rtP.BLDC_Ld
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 223;

                    ;% rtP.BLDC_Lq
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 224;

                    ;% rtP.BLDC_MechInput
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 225;

                    ;% rtP.DatasheetBattery_Np
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 226;

                    ;% rtP.DatasheetBattery_Ns
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 227;

                    ;% rtP.BLDC_Omega_init
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 228;

                    ;% rtP.DatasheetBattery_RInt
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 229;

                    ;% rtP.BLDC_Rs
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 271;

                    ;% rtP.BLDC_Th_init
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 272;

                    ;% rtP.MappedCIEngine_f_air
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 273;

                    ;% rtP.MappedCIEngine_f_co
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 593;

                    ;% rtP.MappedCIEngine_f_co2
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 913;

                    ;% rtP.MappedCIEngine_f_fuel
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 1233;

                    ;% rtP.MappedCIEngine_f_hc
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 1553;

                    ;% rtP.MappedCIEngine_f_nox
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 1873;

                    ;% rtP.MappedCIEngine_f_tbrake
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 2193;

                    ;% rtP.MappedCIEngine_f_tbrake_n_bpt
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 2513;

                    ;% rtP.MappedCIEngine_f_tbrake_t_bpt
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 2529;

                    ;% rtP.BLDC_p
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 2549;

                    ;% rtP.Constant1_Value
                    section.data(32).logicalSrcIdx = 31;
                    section.data(32).dtTransOffset = 2550;

                    ;% rtP.Constant3_Value
                    section.data(33).logicalSrcIdx = 32;
                    section.data(33).dtTransOffset = 2551;

                    ;% rtP.Gain1_Gain
                    section.data(34).logicalSrcIdx = 33;
                    section.data(34).dtTransOffset = 2552;

                    ;% rtP.Bias_Bias
                    section.data(35).logicalSrcIdx = 34;
                    section.data(35).dtTransOffset = 2553;

                    ;% rtP.Constant4_Value
                    section.data(36).logicalSrcIdx = 35;
                    section.data(36).dtTransOffset = 2554;

                    ;% rtP.Constant5_Value
                    section.data(37).logicalSrcIdx = 36;
                    section.data(37).dtTransOffset = 2555;

                    ;% rtP.Gain2_Gain
                    section.data(38).logicalSrcIdx = 37;
                    section.data(38).dtTransOffset = 2556;

                    ;% rtP.Bias2_Bias
                    section.data(39).logicalSrcIdx = 38;
                    section.data(39).dtTransOffset = 2557;

                    ;% rtP.Gain_Gain
                    section.data(40).logicalSrcIdx = 39;
                    section.data(40).dtTransOffset = 2558;

                    ;% rtP.Bias1_Bias
                    section.data(41).logicalSrcIdx = 40;
                    section.data(41).dtTransOffset = 2559;

                    ;% rtP.Constant1_Value_kimdzexz1x
                    section.data(42).logicalSrcIdx = 41;
                    section.data(42).dtTransOffset = 2560;

                    ;% rtP.Constant3_Value_ag4er51bcj
                    section.data(43).logicalSrcIdx = 42;
                    section.data(43).dtTransOffset = 2561;

                    ;% rtP.Gain1_Gain_kc23apyjss
                    section.data(44).logicalSrcIdx = 43;
                    section.data(44).dtTransOffset = 2562;

                    ;% rtP.Bias_Bias_pvrcayevr1
                    section.data(45).logicalSrcIdx = 44;
                    section.data(45).dtTransOffset = 2563;

                    ;% rtP.Constant4_Value_j0el1tqerf
                    section.data(46).logicalSrcIdx = 45;
                    section.data(46).dtTransOffset = 2564;

                    ;% rtP.Constant5_Value_hivcl12fft
                    section.data(47).logicalSrcIdx = 46;
                    section.data(47).dtTransOffset = 2565;

                    ;% rtP.Gain2_Gain_cskldqighc
                    section.data(48).logicalSrcIdx = 47;
                    section.data(48).dtTransOffset = 2566;

                    ;% rtP.Bias2_Bias_ajzwnv2cpb
                    section.data(49).logicalSrcIdx = 48;
                    section.data(49).dtTransOffset = 2567;

                    ;% rtP.Gain_Gain_f4q2bv4ant
                    section.data(50).logicalSrcIdx = 49;
                    section.data(50).dtTransOffset = 2568;

                    ;% rtP.Bias1_Bias_gcbxjqy1ag
                    section.data(51).logicalSrcIdx = 50;
                    section.data(51).dtTransOffset = 2569;

                    ;% rtP.Constant1_Value_atqbaqyuhn
                    section.data(52).logicalSrcIdx = 51;
                    section.data(52).dtTransOffset = 2570;

                    ;% rtP.Constant3_Value_bkypk4xhrd
                    section.data(53).logicalSrcIdx = 52;
                    section.data(53).dtTransOffset = 2571;

                    ;% rtP.Gain1_Gain_agqevzoajc
                    section.data(54).logicalSrcIdx = 53;
                    section.data(54).dtTransOffset = 2572;

                    ;% rtP.Bias_Bias_kp4pcovegv
                    section.data(55).logicalSrcIdx = 54;
                    section.data(55).dtTransOffset = 2573;

                    ;% rtP.Constant4_Value_bwrt5oukhm
                    section.data(56).logicalSrcIdx = 55;
                    section.data(56).dtTransOffset = 2574;

                    ;% rtP.Constant5_Value_abvqtbsmbe
                    section.data(57).logicalSrcIdx = 56;
                    section.data(57).dtTransOffset = 2575;

                    ;% rtP.Gain2_Gain_dfafj4yf5d
                    section.data(58).logicalSrcIdx = 57;
                    section.data(58).dtTransOffset = 2576;

                    ;% rtP.Bias2_Bias_iyf2mr5qig
                    section.data(59).logicalSrcIdx = 58;
                    section.data(59).dtTransOffset = 2577;

                    ;% rtP.Gain_Gain_aj4jewynfg
                    section.data(60).logicalSrcIdx = 59;
                    section.data(60).dtTransOffset = 2578;

                    ;% rtP.Bias1_Bias_bpnnrv2g4v
                    section.data(61).logicalSrcIdx = 60;
                    section.data(61).dtTransOffset = 2579;

                    ;% rtP.IntegratorLimited_LowerSat
                    section.data(62).logicalSrcIdx = 61;
                    section.data(62).dtTransOffset = 2580;

                    ;% rtP.Constant_Value
                    section.data(63).logicalSrcIdx = 62;
                    section.data(63).dtTransOffset = 2581;

                    ;% rtP.Minus120_Value
                    section.data(64).logicalSrcIdx = 63;
                    section.data(64).dtTransOffset = 2582;

                    ;% rtP.Plus120_Value
                    section.data(65).logicalSrcIdx = 64;
                    section.data(65).dtTransOffset = 2586;

                    ;% rtP.Gain2_Gain_jlslrcmtdv
                    section.data(66).logicalSrcIdx = 65;
                    section.data(66).dtTransOffset = 2590;

                    ;% rtP.Constant2_Value
                    section.data(67).logicalSrcIdx = 66;
                    section.data(67).dtTransOffset = 2591;

                    ;% rtP.Constant_Value_ijz5z22oj1
                    section.data(68).logicalSrcIdx = 67;
                    section.data(68).dtTransOffset = 2592;

                    ;% rtP.Bias3_Bias
                    section.data(69).logicalSrcIdx = 68;
                    section.data(69).dtTransOffset = 2593;

                    ;% rtP.Constant7_Value
                    section.data(70).logicalSrcIdx = 69;
                    section.data(70).dtTransOffset = 2594;

                    ;% rtP.Constant9_Value
                    section.data(71).logicalSrcIdx = 70;
                    section.data(71).dtTransOffset = 2595;

                    ;% rtP.Constant8_Value
                    section.data(72).logicalSrcIdx = 71;
                    section.data(72).dtTransOffset = 2596;

                    ;% rtP.Constant10_Value
                    section.data(73).logicalSrcIdx = 72;
                    section.data(73).dtTransOffset = 2597;

                    ;% rtP.Constant11_Value
                    section.data(74).logicalSrcIdx = 73;
                    section.data(74).dtTransOffset = 2598;

                    ;% rtP.Constant2_Value_je4lnbr020
                    section.data(75).logicalSrcIdx = 74;
                    section.data(75).dtTransOffset = 2599;

                    ;% rtP.Constant12_Value
                    section.data(76).logicalSrcIdx = 75;
                    section.data(76).dtTransOffset = 2600;

                    ;% rtP.Constant6_Value
                    section.data(77).logicalSrcIdx = 76;
                    section.data(77).dtTransOffset = 2601;

                    ;% rtP.Bias3_Bias_pumqr42kho
                    section.data(78).logicalSrcIdx = 77;
                    section.data(78).dtTransOffset = 2602;

                    ;% rtP.Constant7_Value_hf0hbvewrl
                    section.data(79).logicalSrcIdx = 78;
                    section.data(79).dtTransOffset = 2603;

                    ;% rtP.Constant9_Value_ovatguv1cd
                    section.data(80).logicalSrcIdx = 79;
                    section.data(80).dtTransOffset = 2604;

                    ;% rtP.Constant8_Value_g0i1o1mso3
                    section.data(81).logicalSrcIdx = 80;
                    section.data(81).dtTransOffset = 2605;

                    ;% rtP.Constant10_Value_j1wyywihpk
                    section.data(82).logicalSrcIdx = 81;
                    section.data(82).dtTransOffset = 2606;

                    ;% rtP.Constant11_Value_nlg4rxjaav
                    section.data(83).logicalSrcIdx = 82;
                    section.data(83).dtTransOffset = 2607;

                    ;% rtP.Constant2_Value_k1svmewxmc
                    section.data(84).logicalSrcIdx = 83;
                    section.data(84).dtTransOffset = 2608;

                    ;% rtP.Constant12_Value_asogurrks4
                    section.data(85).logicalSrcIdx = 84;
                    section.data(85).dtTransOffset = 2609;

                    ;% rtP.Constant6_Value_atr0rui2nv
                    section.data(86).logicalSrcIdx = 85;
                    section.data(86).dtTransOffset = 2610;

                    ;% rtP.Bias3_Bias_dlzcduozuu
                    section.data(87).logicalSrcIdx = 86;
                    section.data(87).dtTransOffset = 2611;

                    ;% rtP.Constant7_Value_ckjsmfweco
                    section.data(88).logicalSrcIdx = 87;
                    section.data(88).dtTransOffset = 2612;

                    ;% rtP.Constant9_Value_b1dkmlfthl
                    section.data(89).logicalSrcIdx = 88;
                    section.data(89).dtTransOffset = 2613;

                    ;% rtP.Constant8_Value_pnqqtlv3vz
                    section.data(90).logicalSrcIdx = 89;
                    section.data(90).dtTransOffset = 2614;

                    ;% rtP.Constant10_Value_gft3qlqgqh
                    section.data(91).logicalSrcIdx = 90;
                    section.data(91).dtTransOffset = 2615;

                    ;% rtP.Constant11_Value_ei54wtxug1
                    section.data(92).logicalSrcIdx = 91;
                    section.data(92).dtTransOffset = 2616;

                    ;% rtP.Constant2_Value_pdtwrvtyzr
                    section.data(93).logicalSrcIdx = 92;
                    section.data(93).dtTransOffset = 2617;

                    ;% rtP.Constant12_Value_eihaiasqnb
                    section.data(94).logicalSrcIdx = 93;
                    section.data(94).dtTransOffset = 2618;

                    ;% rtP.Constant6_Value_d2i3udqljx
                    section.data(95).logicalSrcIdx = 94;
                    section.data(95).dtTransOffset = 2619;

                    ;% rtP.Max_Lampda_PM_rate_Gain
                    section.data(96).logicalSrcIdx = 95;
                    section.data(96).dtTransOffset = 2620;

                    ;% rtP.Gain1_Gain_kogsiikotf
                    section.data(97).logicalSrcIdx = 96;
                    section.data(97).dtTransOffset = 2621;

                    ;% rtP.Gain3_Gain
                    section.data(98).logicalSrcIdx = 97;
                    section.data(98).dtTransOffset = 2622;

                    ;% rtP.Trq_Or_Spd_Threshold
                    section.data(99).logicalSrcIdx = 98;
                    section.data(99).dtTransOffset = 2623;

                    ;% rtP.Trq_Or_Spd_Threshold_bv5qvwcnkb
                    section.data(100).logicalSrcIdx = 99;
                    section.data(100).dtTransOffset = 2624;

                    ;% rtP.Gain_Gain_an2ok5irfz
                    section.data(101).logicalSrcIdx = 100;
                    section.data(101).dtTransOffset = 2625;

                    ;% rtP.Constant2_Value_ozzuwkqilp
                    section.data(102).logicalSrcIdx = 101;
                    section.data(102).dtTransOffset = 2626;

                    ;% rtP.Minus120_Value_micf4v4hxs
                    section.data(103).logicalSrcIdx = 102;
                    section.data(103).dtTransOffset = 2627;

                    ;% rtP.Gain2_Gain_lhlkdqm0ee
                    section.data(104).logicalSrcIdx = 103;
                    section.data(104).dtTransOffset = 2631;

                    ;% rtP.Plus120_Value_hunie3hozg
                    section.data(105).logicalSrcIdx = 104;
                    section.data(105).dtTransOffset = 2632;

                    ;% rtP.Gain3_Gain_oeu1akxnfz
                    section.data(106).logicalSrcIdx = 105;
                    section.data(106).dtTransOffset = 2636;

                    ;% rtP.Gain1_Gain_ovhavq0wpo
                    section.data(107).logicalSrcIdx = 106;
                    section.data(107).dtTransOffset = 2637;

                    ;% rtP.Integrator_IC
                    section.data(108).logicalSrcIdx = 107;
                    section.data(108).dtTransOffset = 2638;

                    ;% rtP.Constant_Value_dpuy0h0ihd
                    section.data(109).logicalSrcIdx = 108;
                    section.data(109).dtTransOffset = 2639;

                    ;% rtP.toRad_Gain
                    section.data(110).logicalSrcIdx = 109;
                    section.data(110).dtTransOffset = 2642;

                    ;% rtP.Constant_Value_jcoszycr0r
                    section.data(111).logicalSrcIdx = 110;
                    section.data(111).dtTransOffset = 2643;

                    ;% rtP.Constant1_Value_n213dknlmm
                    section.data(112).logicalSrcIdx = 111;
                    section.data(112).dtTransOffset = 2644;

                    ;% rtP.Constant2_Value_ntrun4mqdf
                    section.data(113).logicalSrcIdx = 112;
                    section.data(113).dtTransOffset = 2645;

                    ;% rtP.Constant3_Value_jfxy4qopdq
                    section.data(114).logicalSrcIdx = 113;
                    section.data(114).dtTransOffset = 2646;

                    ;% rtP.Constant4_Value_jg1qmih3ue
                    section.data(115).logicalSrcIdx = 114;
                    section.data(115).dtTransOffset = 2647;

                    ;% rtP.Constant5_Value_m54jfbbmbh
                    section.data(116).logicalSrcIdx = 115;
                    section.data(116).dtTransOffset = 2648;

                    ;% rtP.raddeg_Gain
                    section.data(117).logicalSrcIdx = 116;
                    section.data(117).dtTransOffset = 2649;

                    ;% rtP.Amplitude1_Gain
                    section.data(118).logicalSrcIdx = 117;
                    section.data(118).dtTransOffset = 2650;

                    ;% rtP.SignalGenerator_Amplitude
                    section.data(119).logicalSrcIdx = 118;
                    section.data(119).dtTransOffset = 2651;

                    ;% rtP.SignalGenerator_Frequency
                    section.data(120).logicalSrcIdx = 119;
                    section.data(120).dtTransOffset = 2652;

                    ;% rtP.Switch1_Threshold
                    section.data(121).logicalSrcIdx = 120;
                    section.data(121).dtTransOffset = 2653;

                    ;% rtP.Switch1_Threshold_hyh3yfwgbh
                    section.data(122).logicalSrcIdx = 121;
                    section.data(122).dtTransOffset = 2654;

                    ;% rtP.Integrator_IC_lrmnxeinqj
                    section.data(123).logicalSrcIdx = 122;
                    section.data(123).dtTransOffset = 2655;

                    ;% rtP.Integrator_WrappedStateUpperValue
                    section.data(124).logicalSrcIdx = 123;
                    section.data(124).dtTransOffset = 2656;

                    ;% rtP.Integrator_WrappedStateLowerValue
                    section.data(125).logicalSrcIdx = 124;
                    section.data(125).dtTransOffset = 2657;

                    ;% rtP.RPMtodegs_Gain
                    section.data(126).logicalSrcIdx = 125;
                    section.data(126).dtTransOffset = 2658;

                    ;% rtP.Constant2_Value_amvyq0ozrf
                    section.data(127).logicalSrcIdx = 126;
                    section.data(127).dtTransOffset = 2659;

                    ;% rtP.Constant3_Value_clw2lo3chi
                    section.data(128).logicalSrcIdx = 127;
                    section.data(128).dtTransOffset = 2660;

                    ;% rtP.Constant4_Value_nmxg2ourug
                    section.data(129).logicalSrcIdx = 128;
                    section.data(129).dtTransOffset = 2661;

                    ;% rtP.Constant1_Value_dsqxhplhg3
                    section.data(130).logicalSrcIdx = 129;
                    section.data(130).dtTransOffset = 2662;

                    ;% rtP.Constant_Value_cu2gsqbnxd
                    section.data(131).logicalSrcIdx = 130;
                    section.data(131).dtTransOffset = 2663;

                    ;% rtP.Constant_Value_oboowpiodw
                    section.data(132).logicalSrcIdx = 131;
                    section.data(132).dtTransOffset = 2664;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 8;
            section.data(8)  = dumData; %prealloc

                    ;% rtP.R_maxIndex
                    section.data(1).logicalSrcIdx = 132;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.EoHcTable_maxIndex
                    section.data(2).logicalSrcIdx = 133;
                    section.data(2).dtTransOffset = 2;

                    ;% rtP.EoCoTable_maxIndex
                    section.data(3).logicalSrcIdx = 134;
                    section.data(3).dtTransOffset = 4;

                    ;% rtP.EoNOxTable_maxIndex
                    section.data(4).logicalSrcIdx = 135;
                    section.data(4).dtTransOffset = 6;

                    ;% rtP.EoCO2Table_maxIndex
                    section.data(5).logicalSrcIdx = 136;
                    section.data(5).dtTransOffset = 8;

                    ;% rtP.EngTrqTable_maxIndex
                    section.data(6).logicalSrcIdx = 137;
                    section.data(6).dtTransOffset = 10;

                    ;% rtP.FuelMassFlwTable_maxIndex
                    section.data(7).logicalSrcIdx = 138;
                    section.data(7).dtTransOffset = 12;

                    ;% rtP.AirFlowTable_maxIndex
                    section.data(8).logicalSrcIdx = 139;
                    section.data(8).dtTransOffset = 14;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section


            ;%
            ;% Non-auto Data (parameter)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        paramMap.nTotData = nTotData;



    ;%**************************
    ;% Create Block Output Map *
    ;%**************************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 2;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc sigMap
        ;%
        sigMap.nSections           = nTotSects;
        sigMap.sectIdxOffset       = sectIdxOffset;
            sigMap.sections(nTotSects) = dumSection; %prealloc
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (rtB)
        ;%
            section.nData     = 72;
            section.data(72)  = dumData; %prealloc

                    ;% rtB.fdyvfxa4tp
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.nfowuituae
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% rtB.kvdqpvhzmq
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% rtB.fyb11a0byc
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% rtB.aijej34sel
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% rtB.oi4vt50rct
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% rtB.ojrenqmhg3
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% rtB.eefe1liyby
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

                    ;% rtB.fv0duehogi
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 11;

                    ;% rtB.i3rjdtbo1x
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 15;

                    ;% rtB.cfptusc1o2
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 16;

                    ;% rtB.iek4fstubw
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 17;

                    ;% rtB.a0ayb25qmj
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 18;

                    ;% rtB.djbr2nwlhy
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 19;

                    ;% rtB.km0bbxs3pg
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 20;

                    ;% rtB.p4snq0ykvj
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 21;

                    ;% rtB.gg1iibxtko
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 22;

                    ;% rtB.fzpbd0kwko
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 23;

                    ;% rtB.hj0n4eqkhc
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 24;

                    ;% rtB.o4pbpbusow
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 25;

                    ;% rtB.a2bgnx52ge
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 26;

                    ;% rtB.bhs0z1a4bq
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 27;

                    ;% rtB.dj0lrq0jz3
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 28;

                    ;% rtB.e2kxzmdksw
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 29;

                    ;% rtB.agj32u24vd
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 30;

                    ;% rtB.lv12rd3q40
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 31;

                    ;% rtB.dzznc5n5ya
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 32;

                    ;% rtB.authoigqah
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 33;

                    ;% rtB.a2tckjiuqf
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 34;

                    ;% rtB.ix4azagznh
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 35;

                    ;% rtB.jc2b3utact
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 36;

                    ;% rtB.eyst12stjo
                    section.data(32).logicalSrcIdx = 31;
                    section.data(32).dtTransOffset = 37;

                    ;% rtB.oo4kaggwwm
                    section.data(33).logicalSrcIdx = 32;
                    section.data(33).dtTransOffset = 38;

                    ;% rtB.em4keqr4uy
                    section.data(34).logicalSrcIdx = 33;
                    section.data(34).dtTransOffset = 39;

                    ;% rtB.kx0hemlyld
                    section.data(35).logicalSrcIdx = 34;
                    section.data(35).dtTransOffset = 40;

                    ;% rtB.pt45h5hjge
                    section.data(36).logicalSrcIdx = 35;
                    section.data(36).dtTransOffset = 41;

                    ;% rtB.hmxy34r3a0
                    section.data(37).logicalSrcIdx = 36;
                    section.data(37).dtTransOffset = 42;

                    ;% rtB.jhspkh2pnv
                    section.data(38).logicalSrcIdx = 37;
                    section.data(38).dtTransOffset = 43;

                    ;% rtB.egogztggip
                    section.data(39).logicalSrcIdx = 38;
                    section.data(39).dtTransOffset = 44;

                    ;% rtB.gy0z0zpdto
                    section.data(40).logicalSrcIdx = 39;
                    section.data(40).dtTransOffset = 45;

                    ;% rtB.p3wvq04dag
                    section.data(41).logicalSrcIdx = 40;
                    section.data(41).dtTransOffset = 46;

                    ;% rtB.iwc3kjrmco
                    section.data(42).logicalSrcIdx = 41;
                    section.data(42).dtTransOffset = 47;

                    ;% rtB.fi1fzzmmw5
                    section.data(43).logicalSrcIdx = 42;
                    section.data(43).dtTransOffset = 48;

                    ;% rtB.oqrehzq1rd
                    section.data(44).logicalSrcIdx = 43;
                    section.data(44).dtTransOffset = 49;

                    ;% rtB.lpydzdrxfc
                    section.data(45).logicalSrcIdx = 44;
                    section.data(45).dtTransOffset = 53;

                    ;% rtB.aqf34w05ez
                    section.data(46).logicalSrcIdx = 45;
                    section.data(46).dtTransOffset = 57;

                    ;% rtB.khomf1duv0
                    section.data(47).logicalSrcIdx = 46;
                    section.data(47).dtTransOffset = 60;

                    ;% rtB.efzov3ezec
                    section.data(48).logicalSrcIdx = 47;
                    section.data(48).dtTransOffset = 61;

                    ;% rtB.fv5d2sh2lx
                    section.data(49).logicalSrcIdx = 48;
                    section.data(49).dtTransOffset = 62;

                    ;% rtB.nveuw3rqtc
                    section.data(50).logicalSrcIdx = 49;
                    section.data(50).dtTransOffset = 63;

                    ;% rtB.bjvr10i1xh
                    section.data(51).logicalSrcIdx = 50;
                    section.data(51).dtTransOffset = 64;

                    ;% rtB.pntpgyacqb
                    section.data(52).logicalSrcIdx = 51;
                    section.data(52).dtTransOffset = 65;

                    ;% rtB.b2k2rf0t1o
                    section.data(53).logicalSrcIdx = 52;
                    section.data(53).dtTransOffset = 66;

                    ;% rtB.j1gs3wlbyf
                    section.data(54).logicalSrcIdx = 53;
                    section.data(54).dtTransOffset = 67;

                    ;% rtB.jwqy5kjnca
                    section.data(55).logicalSrcIdx = 54;
                    section.data(55).dtTransOffset = 68;

                    ;% rtB.lyvzolqnf4
                    section.data(56).logicalSrcIdx = 55;
                    section.data(56).dtTransOffset = 69;

                    ;% rtB.g52te4dnv1
                    section.data(57).logicalSrcIdx = 56;
                    section.data(57).dtTransOffset = 70;

                    ;% rtB.j5bvpiinqj
                    section.data(58).logicalSrcIdx = 57;
                    section.data(58).dtTransOffset = 71;

                    ;% rtB.hygy1qilge
                    section.data(59).logicalSrcIdx = 58;
                    section.data(59).dtTransOffset = 72;

                    ;% rtB.parcfkhsio
                    section.data(60).logicalSrcIdx = 59;
                    section.data(60).dtTransOffset = 73;

                    ;% rtB.hkoqt4keho
                    section.data(61).logicalSrcIdx = 60;
                    section.data(61).dtTransOffset = 74;

                    ;% rtB.pairspzuzs
                    section.data(62).logicalSrcIdx = 61;
                    section.data(62).dtTransOffset = 75;

                    ;% rtB.defj4le0qu
                    section.data(63).logicalSrcIdx = 62;
                    section.data(63).dtTransOffset = 76;

                    ;% rtB.jujtr2tg5z
                    section.data(64).logicalSrcIdx = 63;
                    section.data(64).dtTransOffset = 77;

                    ;% rtB.l1nh51d3ja
                    section.data(65).logicalSrcIdx = 64;
                    section.data(65).dtTransOffset = 78;

                    ;% rtB.jmwba0ymud
                    section.data(66).logicalSrcIdx = 65;
                    section.data(66).dtTransOffset = 79;

                    ;% rtB.hapipevwha
                    section.data(67).logicalSrcIdx = 66;
                    section.data(67).dtTransOffset = 80;

                    ;% rtB.pdiw5iqass
                    section.data(68).logicalSrcIdx = 67;
                    section.data(68).dtTransOffset = 81;

                    ;% rtB.hkg2tchhax
                    section.data(69).logicalSrcIdx = 68;
                    section.data(69).dtTransOffset = 82;

                    ;% rtB.pxpvevgrie
                    section.data(70).logicalSrcIdx = 69;
                    section.data(70).dtTransOffset = 83;

                    ;% rtB.ktnbcplp2i
                    section.data(71).logicalSrcIdx = 70;
                    section.data(71).dtTransOffset = 84;

                    ;% rtB.gjnfdmbcjm
                    section.data(72).logicalSrcIdx = 71;
                    section.data(72).dtTransOffset = 85;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 9;
            section.data(9)  = dumData; %prealloc

                    ;% rtB.bvn1smh1wj
                    section.data(1).logicalSrcIdx = 72;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.ljru5rp5pg
                    section.data(2).logicalSrcIdx = 73;
                    section.data(2).dtTransOffset = 1;

                    ;% rtB.dqvtfxq5pg
                    section.data(3).logicalSrcIdx = 74;
                    section.data(3).dtTransOffset = 2;

                    ;% rtB.fylseu1fes
                    section.data(4).logicalSrcIdx = 75;
                    section.data(4).dtTransOffset = 3;

                    ;% rtB.akfaoup2b2
                    section.data(5).logicalSrcIdx = 76;
                    section.data(5).dtTransOffset = 4;

                    ;% rtB.cmqpjmrsw2
                    section.data(6).logicalSrcIdx = 77;
                    section.data(6).dtTransOffset = 5;

                    ;% rtB.duszlmyn0l
                    section.data(7).logicalSrcIdx = 78;
                    section.data(7).dtTransOffset = 6;

                    ;% rtB.pduf40h0yn
                    section.data(8).logicalSrcIdx = 79;
                    section.data(8).dtTransOffset = 7;

                    ;% rtB.jfvfvv3giv
                    section.data(9).logicalSrcIdx = 80;
                    section.data(9).dtTransOffset = 8;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
            clear section


            ;%
            ;% Non-auto Data (signal)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        sigMap.nTotData = nTotData;



    ;%*******************
    ;% Create DWork Map *
    ;%*******************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 3;
        sectIdxOffset = 2;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc dworkMap
        ;%
        dworkMap.nSections           = nTotSects;
        dworkMap.sectIdxOffset       = sectIdxOffset;
            dworkMap.sections(nTotSects) = dumSection; %prealloc
        dworkMap.nTotData            = -1;

        ;%
        ;% Auto data (rtDW)
        ;%
            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% rtDW.avkff5cs3v.LoggedData
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.mzdo32klye.LoggedData
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.gjyqt1hwd3.LoggedData
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.cqvoje5ho5.LoggedData
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.a44i1qtvtw.LoggedData
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.ih5pmp5chi.LoggedData
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% rtDW.i3v3y1llki
                    section.data(1).logicalSrcIdx = 6;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.dokiorwuv5
                    section.data(2).logicalSrcIdx = 7;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.jlyvcbibun
                    section.data(3).logicalSrcIdx = 8;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.njopz31ksb
                    section.data(4).logicalSrcIdx = 9;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.le5se2ckp5
                    section.data(5).logicalSrcIdx = 10;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.lve2pwc1qx
                    section.data(6).logicalSrcIdx = 11;
                    section.data(6).dtTransOffset = 5;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 32;
            section.data(32)  = dumData; %prealloc

                    ;% rtDW.kwqc3w5qsd
                    section.data(1).logicalSrcIdx = 12;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.l5ccmkoqga
                    section.data(2).logicalSrcIdx = 13;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.lggybcog5h
                    section.data(3).logicalSrcIdx = 14;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.e4yp0ut4l1
                    section.data(4).logicalSrcIdx = 15;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.ljyxtoiaxn
                    section.data(5).logicalSrcIdx = 16;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.huibxjzrlf
                    section.data(6).logicalSrcIdx = 17;
                    section.data(6).dtTransOffset = 5;

                    ;% rtDW.jqtcbyvb4q
                    section.data(7).logicalSrcIdx = 18;
                    section.data(7).dtTransOffset = 6;

                    ;% rtDW.pnompecjp4
                    section.data(8).logicalSrcIdx = 19;
                    section.data(8).dtTransOffset = 7;

                    ;% rtDW.lgvgb0bfiz
                    section.data(9).logicalSrcIdx = 20;
                    section.data(9).dtTransOffset = 8;

                    ;% rtDW.gxqjpzrbio
                    section.data(10).logicalSrcIdx = 21;
                    section.data(10).dtTransOffset = 9;

                    ;% rtDW.cblqvhc4lg
                    section.data(11).logicalSrcIdx = 22;
                    section.data(11).dtTransOffset = 10;

                    ;% rtDW.fwyecslys2
                    section.data(12).logicalSrcIdx = 23;
                    section.data(12).dtTransOffset = 11;

                    ;% rtDW.jzfmqldcwd
                    section.data(13).logicalSrcIdx = 24;
                    section.data(13).dtTransOffset = 12;

                    ;% rtDW.fmiwrydvs2
                    section.data(14).logicalSrcIdx = 25;
                    section.data(14).dtTransOffset = 13;

                    ;% rtDW.n0up5wu5m1
                    section.data(15).logicalSrcIdx = 26;
                    section.data(15).dtTransOffset = 14;

                    ;% rtDW.ducvjjg20z
                    section.data(16).logicalSrcIdx = 27;
                    section.data(16).dtTransOffset = 15;

                    ;% rtDW.mntjd4rtyd
                    section.data(17).logicalSrcIdx = 28;
                    section.data(17).dtTransOffset = 16;

                    ;% rtDW.mxuiebor3g
                    section.data(18).logicalSrcIdx = 29;
                    section.data(18).dtTransOffset = 17;

                    ;% rtDW.gsaioffcba
                    section.data(19).logicalSrcIdx = 30;
                    section.data(19).dtTransOffset = 18;

                    ;% rtDW.bivwyexrzk
                    section.data(20).logicalSrcIdx = 31;
                    section.data(20).dtTransOffset = 19;

                    ;% rtDW.in45u4qlpg
                    section.data(21).logicalSrcIdx = 32;
                    section.data(21).dtTransOffset = 20;

                    ;% rtDW.oq2tlyjoxk
                    section.data(22).logicalSrcIdx = 33;
                    section.data(22).dtTransOffset = 21;

                    ;% rtDW.osvc52zbdn
                    section.data(23).logicalSrcIdx = 34;
                    section.data(23).dtTransOffset = 22;

                    ;% rtDW.glckwxkpxy
                    section.data(24).logicalSrcIdx = 35;
                    section.data(24).dtTransOffset = 23;

                    ;% rtDW.oo4t3xcua2
                    section.data(25).logicalSrcIdx = 36;
                    section.data(25).dtTransOffset = 24;

                    ;% rtDW.eva4ztbj44
                    section.data(26).logicalSrcIdx = 37;
                    section.data(26).dtTransOffset = 25;

                    ;% rtDW.lryrlbazgx
                    section.data(27).logicalSrcIdx = 38;
                    section.data(27).dtTransOffset = 26;

                    ;% rtDW.htsaf52tj2
                    section.data(28).logicalSrcIdx = 39;
                    section.data(28).dtTransOffset = 27;

                    ;% rtDW.gt354wtaj0
                    section.data(29).logicalSrcIdx = 40;
                    section.data(29).dtTransOffset = 28;

                    ;% rtDW.a0nir1pp1r
                    section.data(30).logicalSrcIdx = 41;
                    section.data(30).dtTransOffset = 29;

                    ;% rtDW.pkr1zun1m3
                    section.data(31).logicalSrcIdx = 42;
                    section.data(31).dtTransOffset = 30;

                    ;% rtDW.phu2ogaeea
                    section.data(32).logicalSrcIdx = 43;
                    section.data(32).dtTransOffset = 31;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section


            ;%
            ;% Non-auto Data (dwork)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        dworkMap.nTotData = nTotData;



    ;%
    ;% Add individual maps to base struct.
    ;%

    targMap.paramMap  = paramMap;
    targMap.signalMap = sigMap;
    targMap.dworkMap  = dworkMap;

    ;%
    ;% Add checksums to base struct.
    ;%


    targMap.checksum0 = 1731618281;
    targMap.checksum1 = 510667600;
    targMap.checksum2 = 3146656349;
    targMap.checksum3 = 3818291459;

