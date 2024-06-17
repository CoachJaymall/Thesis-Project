    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 3;
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
            section.nData     = 181;
            section.data(181)  = dumData; %prealloc

                    ;% rtP.Batt_Cap
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.Batt_Parr
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.Batt_Series
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% rtP.Dyno_Ke
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% rtP.Dyno_Kt
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% rtP.Dyno_Ratio
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% rtP.Fuel_Map
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% rtP.Fuel_MapE
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 90;

                    ;% rtP.Power_Map
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 174;

                    ;% rtP.Power_Thr_Map
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 258;

                    ;% rtP.SideA_N
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 324;

                    ;% rtP.SideA_Physical_Param
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 325;

                    ;% rtP.SideA_RatedTrq
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 328;

                    ;% rtP.SideA_Rs
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 329;

                    ;% rtP.SideA_lambda
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 330;

                    ;% rtP.Spd_BP
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 331;

                    ;% rtP.Trq_BP
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 338;

                    ;% rtP.DatasheetBattery_BattTempBp
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 350;

                    ;% rtP.DatasheetBattery_CapLUTBp
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 357;

                    ;% rtP.DatasheetBattery_CapSOCBp
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 458;

                    ;% rtP.DatasheetBattery_Em
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 464;

                    ;% rtP.SurfaceMountPMController1_Fs
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 565;

                    ;% rtP.SurfaceMountPMController1_Fv
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 566;

                    ;% rtP.SurfaceMountPMController1_Jcomp
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 567;

                    ;% rtP.SurfaceMountPMController1_Ki
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 568;

                    ;% rtP.SurfaceMountPMController1_Kisa
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 569;

                    ;% rtP.SurfaceMountPMController1_Kp_d
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 570;

                    ;% rtP.SurfaceMountPMController1_Kp_q
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 571;

                    ;% rtP.SurfaceMountPMController1_Ksa
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 572;

                    ;% rtP.SurfaceMountPMController1_Ksf
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 573;

                    ;% rtP.DatasheetBattery_RInt
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 574;

                    ;% rtP.DatasheetBattery_Tc
                    section.data(32).logicalSrcIdx = 31;
                    section.data(32).dtTransOffset = 616;

                    ;% rtP.DatasheetBattery_Vinit
                    section.data(33).logicalSrcIdx = 32;
                    section.data(33).dtTransOffset = 617;

                    ;% rtP.SurfaceMountPMController1_ba
                    section.data(34).logicalSrcIdx = 33;
                    section.data(34).dtTransOffset = 618;

                    ;% rtP.SKP6485_idq0
                    section.data(35).logicalSrcIdx = 34;
                    section.data(35).dtTransOffset = 619;

                    ;% rtP.SurfaceMountPMController1_idq_limits
                    section.data(36).logicalSrcIdx = 35;
                    section.data(36).dtTransOffset = 621;

                    ;% rtP.SKP6485_omega_init
                    section.data(37).logicalSrcIdx = 36;
                    section.data(37).dtTransOffset = 622;

                    ;% rtP.SKP6485_theta_init
                    section.data(38).logicalSrcIdx = 37;
                    section.data(38).dtTransOffset = 623;

                    ;% rtP.Constant_Value
                    section.data(39).logicalSrcIdx = 38;
                    section.data(39).dtTransOffset = 624;

                    ;% rtP.Constant1_Value
                    section.data(40).logicalSrcIdx = 39;
                    section.data(40).dtTransOffset = 625;

                    ;% rtP.Merge_InitialOutput
                    section.data(41).logicalSrcIdx = 40;
                    section.data(41).dtTransOffset = 626;

                    ;% rtP.Merge1_InitialOutput
                    section.data(42).logicalSrcIdx = 41;
                    section.data(42).dtTransOffset = 627;

                    ;% rtP.Constant2_Value
                    section.data(43).logicalSrcIdx = 42;
                    section.data(43).dtTransOffset = 628;

                    ;% rtP.Constant3_Value
                    section.data(44).logicalSrcIdx = 43;
                    section.data(44).dtTransOffset = 629;

                    ;% rtP.Constant5_Value
                    section.data(45).logicalSrcIdx = 44;
                    section.data(45).dtTransOffset = 630;

                    ;% rtP.Gain_Gain
                    section.data(46).logicalSrcIdx = 45;
                    section.data(46).dtTransOffset = 631;

                    ;% rtP.Gain1_Gain
                    section.data(47).logicalSrcIdx = 46;
                    section.data(47).dtTransOffset = 632;

                    ;% rtP.Gain5_Gain
                    section.data(48).logicalSrcIdx = 47;
                    section.data(48).dtTransOffset = 633;

                    ;% rtP.Gain4_Gain
                    section.data(49).logicalSrcIdx = 48;
                    section.data(49).dtTransOffset = 634;

                    ;% rtP.Gain2_Gain
                    section.data(50).logicalSrcIdx = 49;
                    section.data(50).dtTransOffset = 635;

                    ;% rtP.Gain3_Gain
                    section.data(51).logicalSrcIdx = 50;
                    section.data(51).dtTransOffset = 636;

                    ;% rtP.Gain1_Gain_j1b2wfl0wo
                    section.data(52).logicalSrcIdx = 51;
                    section.data(52).dtTransOffset = 637;

                    ;% rtP.Merge1_InitialOutput_j4un0hwehg
                    section.data(53).logicalSrcIdx = 52;
                    section.data(53).dtTransOffset = 638;

                    ;% rtP.Proportional_Gain3_Gain
                    section.data(54).logicalSrcIdx = 53;
                    section.data(54).dtTransOffset = 639;

                    ;% rtP.UnitDelay_InitialCondition
                    section.data(55).logicalSrcIdx = 54;
                    section.data(55).dtTransOffset = 640;

                    ;% rtP.Gain1_Gain_he3uzhz5qz
                    section.data(56).logicalSrcIdx = 55;
                    section.data(56).dtTransOffset = 641;

                    ;% rtP.Saturation_UpperSat
                    section.data(57).logicalSrcIdx = 56;
                    section.data(57).dtTransOffset = 642;

                    ;% rtP.Saturation_LowerSat
                    section.data(58).logicalSrcIdx = 57;
                    section.data(58).dtTransOffset = 643;

                    ;% rtP.UnitDelay_InitialCondition_cpl50tg2hx
                    section.data(59).logicalSrcIdx = 58;
                    section.data(59).dtTransOffset = 644;

                    ;% rtP.Gain1_Gain_nnzhsn1hyd
                    section.data(60).logicalSrcIdx = 59;
                    section.data(60).dtTransOffset = 645;

                    ;% rtP.Saturation_UpperSat_phs0dpqpzg
                    section.data(61).logicalSrcIdx = 60;
                    section.data(61).dtTransOffset = 646;

                    ;% rtP.Saturation_LowerSat_gdduvb3oo2
                    section.data(62).logicalSrcIdx = 61;
                    section.data(62).dtTransOffset = 647;

                    ;% rtP.Proportional_Gain2_Gain
                    section.data(63).logicalSrcIdx = 62;
                    section.data(63).dtTransOffset = 648;

                    ;% rtP.Gain1_Gain_fvtzit2ppk
                    section.data(64).logicalSrcIdx = 63;
                    section.data(64).dtTransOffset = 649;

                    ;% rtP.Gain2_Gain_en3fcdxiec
                    section.data(65).logicalSrcIdx = 64;
                    section.data(65).dtTransOffset = 650;

                    ;% rtP.Gain3_Gain_h5v1k1sppn
                    section.data(66).logicalSrcIdx = 65;
                    section.data(66).dtTransOffset = 651;

                    ;% rtP.Gain4_Gain_ne1f41rvzn
                    section.data(67).logicalSrcIdx = 66;
                    section.data(67).dtTransOffset = 652;

                    ;% rtP.Constant4_Value
                    section.data(68).logicalSrcIdx = 67;
                    section.data(68).dtTransOffset = 653;

                    ;% rtP.Gain1_Gain_c2kuo5vmhc
                    section.data(69).logicalSrcIdx = 68;
                    section.data(69).dtTransOffset = 654;

                    ;% rtP.Constant1_Value_brfyntmkio
                    section.data(70).logicalSrcIdx = 69;
                    section.data(70).dtTransOffset = 655;

                    ;% rtP.DiscreteTimeIntegrator_gainval
                    section.data(71).logicalSrcIdx = 70;
                    section.data(71).dtTransOffset = 656;

                    ;% rtP.DiscreteTimeIntegrator_IC
                    section.data(72).logicalSrcIdx = 71;
                    section.data(72).dtTransOffset = 657;

                    ;% rtP.DiscreteTimeIntegrator1_gainval
                    section.data(73).logicalSrcIdx = 72;
                    section.data(73).dtTransOffset = 658;

                    ;% rtP.DiscreteTimeIntegrator1_IC
                    section.data(74).logicalSrcIdx = 73;
                    section.data(74).dtTransOffset = 659;

                    ;% rtP.DiscreteTimeIntegrator_gainval_p43vz5tnpd
                    section.data(75).logicalSrcIdx = 74;
                    section.data(75).dtTransOffset = 660;

                    ;% rtP.DiscreteTimeIntegrator_IC_nipgxr4w4m
                    section.data(76).logicalSrcIdx = 75;
                    section.data(76).dtTransOffset = 661;

                    ;% rtP.uDLookupTable_bp01Data
                    section.data(77).logicalSrcIdx = 76;
                    section.data(77).dtTransOffset = 662;

                    ;% rtP.uDLookupTable_bp02Data
                    section.data(78).logicalSrcIdx = 77;
                    section.data(78).dtTransOffset = 673;

                    ;% rtP.uDLookupTable1_tableData
                    section.data(79).logicalSrcIdx = 78;
                    section.data(79).dtTransOffset = 679;

                    ;% rtP.Switch_Threshold
                    section.data(80).logicalSrcIdx = 79;
                    section.data(80).dtTransOffset = 690;

                    ;% rtP.Constant2_Value_nzc55mhdyv
                    section.data(81).logicalSrcIdx = 80;
                    section.data(81).dtTransOffset = 691;

                    ;% rtP.Constant_Value_kkku1dkpit
                    section.data(82).logicalSrcIdx = 81;
                    section.data(82).dtTransOffset = 692;

                    ;% rtP.uDLookupTable2_tableData
                    section.data(83).logicalSrcIdx = 82;
                    section.data(83).dtTransOffset = 693;

                    ;% rtP.uDLookupTable2_bp01Data
                    section.data(84).logicalSrcIdx = 83;
                    section.data(84).dtTransOffset = 753;

                    ;% rtP.uDLookupTable2_bp02Data
                    section.data(85).logicalSrcIdx = 84;
                    section.data(85).dtTransOffset = 763;

                    ;% rtP.Switch1_Threshold
                    section.data(86).logicalSrcIdx = 85;
                    section.data(86).dtTransOffset = 769;

                    ;% rtP.Switch4_Threshold
                    section.data(87).logicalSrcIdx = 86;
                    section.data(87).dtTransOffset = 770;

                    ;% rtP.Constant_Value_lsistt0yxv
                    section.data(88).logicalSrcIdx = 87;
                    section.data(88).dtTransOffset = 771;

                    ;% rtP.Switch2_Threshold
                    section.data(89).logicalSrcIdx = 88;
                    section.data(89).dtTransOffset = 772;

                    ;% rtP.Switch1_Threshold_er3fpts1xb
                    section.data(90).logicalSrcIdx = 89;
                    section.data(90).dtTransOffset = 773;

                    ;% rtP.Merge_InitialOutput_l2wioipoqf
                    section.data(91).logicalSrcIdx = 90;
                    section.data(91).dtTransOffset = 774;

                    ;% rtP.Constant2_Value_ibttoaofbk
                    section.data(92).logicalSrcIdx = 91;
                    section.data(92).dtTransOffset = 775;

                    ;% rtP.Constant3_Value_hvfq5alqlg
                    section.data(93).logicalSrcIdx = 92;
                    section.data(93).dtTransOffset = 776;

                    ;% rtP.Constant4_Value_fecgcw2rtb
                    section.data(94).logicalSrcIdx = 93;
                    section.data(94).dtTransOffset = 788;

                    ;% rtP.Constant5_Value_axuapffnub
                    section.data(95).logicalSrcIdx = 94;
                    section.data(95).dtTransOffset = 789;

                    ;% rtP.Constant_Value_ea5wuf1vfl
                    section.data(96).logicalSrcIdx = 95;
                    section.data(96).dtTransOffset = 790;

                    ;% rtP.Switch2_Threshold_bn224qmpbp
                    section.data(97).logicalSrcIdx = 96;
                    section.data(97).dtTransOffset = 791;

                    ;% rtP.Switch1_Threshold_n1hoa2ckzb
                    section.data(98).logicalSrcIdx = 97;
                    section.data(98).dtTransOffset = 792;

                    ;% rtP.Constant_Value_m22jzxcnam
                    section.data(99).logicalSrcIdx = 98;
                    section.data(99).dtTransOffset = 793;

                    ;% rtP.Constant2_Value_fkd3f5524d
                    section.data(100).logicalSrcIdx = 99;
                    section.data(100).dtTransOffset = 794;

                    ;% rtP.Constant3_Value_mwesjrmlpm
                    section.data(101).logicalSrcIdx = 100;
                    section.data(101).dtTransOffset = 795;

                    ;% rtP.Constant4_Value_mph0ksevah
                    section.data(102).logicalSrcIdx = 101;
                    section.data(102).dtTransOffset = 807;

                    ;% rtP.Constant5_Value_p2jqkjofwo
                    section.data(103).logicalSrcIdx = 102;
                    section.data(103).dtTransOffset = 808;

                    ;% rtP.Constant1_Value_eafxkgr2qu
                    section.data(104).logicalSrcIdx = 103;
                    section.data(104).dtTransOffset = 809;

                    ;% rtP.Step_Time
                    section.data(105).logicalSrcIdx = 104;
                    section.data(105).dtTransOffset = 810;

                    ;% rtP.Step_Y0
                    section.data(106).logicalSrcIdx = 105;
                    section.data(106).dtTransOffset = 811;

                    ;% rtP.Step_YFinal
                    section.data(107).logicalSrcIdx = 106;
                    section.data(107).dtTransOffset = 812;

                    ;% rtP.fromWS_Signal1_Time0
                    section.data(108).logicalSrcIdx = 107;
                    section.data(108).dtTransOffset = 813;

                    ;% rtP.fromWS_Signal1_Data0
                    section.data(109).logicalSrcIdx = 108;
                    section.data(109).dtTransOffset = 828;

                    ;% rtP.Int_UpperSat
                    section.data(110).logicalSrcIdx = 109;
                    section.data(110).dtTransOffset = 843;

                    ;% rtP.Int_LowerSat
                    section.data(111).logicalSrcIdx = 110;
                    section.data(111).dtTransOffset = 844;

                    ;% rtP.fromWS_Signal1_Time0_ommwt43mku
                    section.data(112).logicalSrcIdx = 111;
                    section.data(112).dtTransOffset = 845;

                    ;% rtP.fromWS_Signal1_Data0_lxog1ybljy
                    section.data(113).logicalSrcIdx = 112;
                    section.data(113).dtTransOffset = 856;

                    ;% rtP.fromWS_Signal1_Time0_pgpp53252z
                    section.data(114).logicalSrcIdx = 113;
                    section.data(114).dtTransOffset = 867;

                    ;% rtP.fromWS_Signal1_Data0_n4yqnlgdbj
                    section.data(115).logicalSrcIdx = 114;
                    section.data(115).dtTransOffset = 875;

                    ;% rtP.fromWS_Signal1_Time0_eamifk5xcs
                    section.data(116).logicalSrcIdx = 115;
                    section.data(116).dtTransOffset = 883;

                    ;% rtP.fromWS_Signal1_Data0_prwgobmyi3
                    section.data(117).logicalSrcIdx = 116;
                    section.data(117).dtTransOffset = 895;

                    ;% rtP.Merge1_InitialOutput_ngwc5befhy
                    section.data(118).logicalSrcIdx = 117;
                    section.data(118).dtTransOffset = 907;

                    ;% rtP.Merge2_InitialOutput
                    section.data(119).logicalSrcIdx = 118;
                    section.data(119).dtTransOffset = 908;

                    ;% rtP.Merge3_InitialOutput
                    section.data(120).logicalSrcIdx = 119;
                    section.data(120).dtTransOffset = 909;

                    ;% rtP.Merge_InitialOutput_htptbem0s2
                    section.data(121).logicalSrcIdx = 120;
                    section.data(121).dtTransOffset = 910;

                    ;% rtP.DA50TorqueMap_tableData
                    section.data(122).logicalSrcIdx = 121;
                    section.data(122).dtTransOffset = 911;

                    ;% rtP.DA50TorqueMap_bp01Data
                    section.data(123).logicalSrcIdx = 122;
                    section.data(123).dtTransOffset = 977;

                    ;% rtP.DA50TorqueMap_bp02Data
                    section.data(124).logicalSrcIdx = 123;
                    section.data(124).dtTransOffset = 988;

                    ;% rtP.DA50PowerMap_tableData
                    section.data(125).logicalSrcIdx = 124;
                    section.data(125).dtTransOffset = 994;

                    ;% rtP.DA50PowerMap_bp01Data
                    section.data(126).logicalSrcIdx = 125;
                    section.data(126).dtTransOffset = 1060;

                    ;% rtP.DA50PowerMap_bp02Data
                    section.data(127).logicalSrcIdx = 126;
                    section.data(127).dtTransOffset = 1071;

                    ;% rtP.rpmtorads_Gain
                    section.data(128).logicalSrcIdx = 127;
                    section.data(128).dtTransOffset = 1077;

                    ;% rtP.Integrator_IC
                    section.data(129).logicalSrcIdx = 128;
                    section.data(129).dtTransOffset = 1078;

                    ;% rtP.Gain1_Gain_nd3h1ot2bp
                    section.data(130).logicalSrcIdx = 129;
                    section.data(130).dtTransOffset = 1079;

                    ;% rtP.kgstogmin_Gain
                    section.data(131).logicalSrcIdx = 130;
                    section.data(131).dtTransOffset = 1080;

                    ;% rtP.Integrator_UpperSat
                    section.data(132).logicalSrcIdx = 131;
                    section.data(132).dtTransOffset = 1081;

                    ;% rtP.Integrator_LowerSat
                    section.data(133).logicalSrcIdx = 132;
                    section.data(133).dtTransOffset = 1082;

                    ;% rtP.Int1_WrappedStateUpperValue
                    section.data(134).logicalSrcIdx = 133;
                    section.data(134).dtTransOffset = 1083;

                    ;% rtP.Int1_WrappedStateLowerValue
                    section.data(135).logicalSrcIdx = 134;
                    section.data(135).dtTransOffset = 1084;

                    ;% rtP.Integrator_UpperSat_dip02x0ffl
                    section.data(136).logicalSrcIdx = 135;
                    section.data(136).dtTransOffset = 1085;

                    ;% rtP.Integrator_LowerSat_bbrmas44s3
                    section.data(137).logicalSrcIdx = 136;
                    section.data(137).dtTransOffset = 1086;

                    ;% rtP.Gain2_Gain_hwyq1kurck
                    section.data(138).logicalSrcIdx = 137;
                    section.data(138).dtTransOffset = 1087;

                    ;% rtP.Gain3_Gain_lvn3xsxcbg
                    section.data(139).logicalSrcIdx = 138;
                    section.data(139).dtTransOffset = 1088;

                    ;% rtP.Gain1_Gain_heyv1n0f4a
                    section.data(140).logicalSrcIdx = 139;
                    section.data(140).dtTransOffset = 1089;

                    ;% rtP.Gain4_Gain_c032xsbfri
                    section.data(141).logicalSrcIdx = 140;
                    section.data(141).dtTransOffset = 1090;

                    ;% rtP.IntegratorLimited_LowerSat
                    section.data(142).logicalSrcIdx = 141;
                    section.data(142).dtTransOffset = 1091;

                    ;% rtP.Integrator_IC_ahzk3fe0wi
                    section.data(143).logicalSrcIdx = 142;
                    section.data(143).dtTransOffset = 1092;

                    ;% rtP.Integrator_WrappedStateUpperValue
                    section.data(144).logicalSrcIdx = 143;
                    section.data(144).dtTransOffset = 1093;

                    ;% rtP.Integrator_WrappedStateLowerValue
                    section.data(145).logicalSrcIdx = 144;
                    section.data(145).dtTransOffset = 1094;

                    ;% rtP.RPMtodegs_Gain
                    section.data(146).logicalSrcIdx = 145;
                    section.data(146).dtTransOffset = 1095;

                    ;% rtP.Gain5_Gain_ofpzj4djyh
                    section.data(147).logicalSrcIdx = 146;
                    section.data(147).dtTransOffset = 1096;

                    ;% rtP.Gain_Gain_a2pdrz3qwa
                    section.data(148).logicalSrcIdx = 147;
                    section.data(148).dtTransOffset = 1097;

                    ;% rtP.Gain1_Gain_p2f3paaf35
                    section.data(149).logicalSrcIdx = 148;
                    section.data(149).dtTransOffset = 1098;

                    ;% rtP.Gain4_Gain_a3qhxjwm2o
                    section.data(150).logicalSrcIdx = 149;
                    section.data(150).dtTransOffset = 1099;

                    ;% rtP.Gain2_Gain_f3g2yr2rkw
                    section.data(151).logicalSrcIdx = 150;
                    section.data(151).dtTransOffset = 1100;

                    ;% rtP.Gain3_Gain_kigulbfrzl
                    section.data(152).logicalSrcIdx = 151;
                    section.data(152).dtTransOffset = 1101;

                    ;% rtP.Constant_Value_in3f0w41r2
                    section.data(153).logicalSrcIdx = 152;
                    section.data(153).dtTransOffset = 1102;

                    ;% rtP.Constant1_Value_bpuwj1x24m
                    section.data(154).logicalSrcIdx = 153;
                    section.data(154).dtTransOffset = 1103;

                    ;% rtP.Constant2_Value_iswfbqmgg0
                    section.data(155).logicalSrcIdx = 154;
                    section.data(155).dtTransOffset = 1104;

                    ;% rtP.Constant3_Value_clw2lo3chi
                    section.data(156).logicalSrcIdx = 155;
                    section.data(156).dtTransOffset = 1105;

                    ;% rtP.Constant4_Value_o2jsgu5bg0
                    section.data(157).logicalSrcIdx = 156;
                    section.data(157).dtTransOffset = 1106;

                    ;% rtP.Constant1_Value_ohpunqj1gy
                    section.data(158).logicalSrcIdx = 157;
                    section.data(158).dtTransOffset = 1107;

                    ;% rtP.Constant3_Value_otox1iiiva
                    section.data(159).logicalSrcIdx = 158;
                    section.data(159).dtTransOffset = 1108;

                    ;% rtP.Constant5_Value_n1ykd3pjvs
                    section.data(160).logicalSrcIdx = 159;
                    section.data(160).dtTransOffset = 1109;

                    ;% rtP.Constant1_Value_mj3ya5njvu
                    section.data(161).logicalSrcIdx = 160;
                    section.data(161).dtTransOffset = 1110;

                    ;% rtP.Constant_Value_c45tuyaygc
                    section.data(162).logicalSrcIdx = 161;
                    section.data(162).dtTransOffset = 1111;

                    ;% rtP.Constant2_Value_m2kdydkjx0
                    section.data(163).logicalSrcIdx = 162;
                    section.data(163).dtTransOffset = 1113;

                    ;% rtP.Constant1_Value_bg0rrb32ed
                    section.data(164).logicalSrcIdx = 163;
                    section.data(164).dtTransOffset = 1114;

                    ;% rtP.Constant_Value_go40v4ie0s
                    section.data(165).logicalSrcIdx = 164;
                    section.data(165).dtTransOffset = 1115;

                    ;% rtP.Constant1_Value_kozehzplrf
                    section.data(166).logicalSrcIdx = 165;
                    section.data(166).dtTransOffset = 1117;

                    ;% rtP.Constant_Value_dm14eym3wc
                    section.data(167).logicalSrcIdx = 166;
                    section.data(167).dtTransOffset = 1118;

                    ;% rtP.Constant1_Value_k5ndhlm4pr
                    section.data(168).logicalSrcIdx = 167;
                    section.data(168).dtTransOffset = 1120;

                    ;% rtP.Constant2_Value_fw4dwfnqy4
                    section.data(169).logicalSrcIdx = 168;
                    section.data(169).dtTransOffset = 1121;

                    ;% rtP.Constant1_Value_om5j34o2qt
                    section.data(170).logicalSrcIdx = 169;
                    section.data(170).dtTransOffset = 1122;

                    ;% rtP.Constant2_Value_kk042enjt5
                    section.data(171).logicalSrcIdx = 170;
                    section.data(171).dtTransOffset = 1124;

                    ;% rtP.Constant1_Value_nwflgkncxk
                    section.data(172).logicalSrcIdx = 171;
                    section.data(172).dtTransOffset = 1125;

                    ;% rtP.Constant_Value_aqptyhwws5
                    section.data(173).logicalSrcIdx = 172;
                    section.data(173).dtTransOffset = 1126;

                    ;% rtP.Constant1_Value_il2awj2dhq
                    section.data(174).logicalSrcIdx = 173;
                    section.data(174).dtTransOffset = 1128;

                    ;% rtP.Constant_Value_pf0letx30a
                    section.data(175).logicalSrcIdx = 174;
                    section.data(175).dtTransOffset = 1129;

                    ;% rtP.Constant1_Value_na2pva40rs
                    section.data(176).logicalSrcIdx = 175;
                    section.data(176).dtTransOffset = 1131;

                    ;% rtP.Constant2_Value_nligrrj1ds
                    section.data(177).logicalSrcIdx = 176;
                    section.data(177).dtTransOffset = 1132;

                    ;% rtP.Constant1_Value_b2jt3bjlb1
                    section.data(178).logicalSrcIdx = 177;
                    section.data(178).dtTransOffset = 1133;

                    ;% rtP.Constant2_Value_e34qlb3i30
                    section.data(179).logicalSrcIdx = 178;
                    section.data(179).dtTransOffset = 1135;

                    ;% rtP.Constant1_Value_igomjraxnc
                    section.data(180).logicalSrcIdx = 179;
                    section.data(180).dtTransOffset = 1136;

                    ;% rtP.Constant2_Value_hsqnj2ufwi
                    section.data(181).logicalSrcIdx = 180;
                    section.data(181).dtTransOffset = 1138;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 13;
            section.data(13)  = dumData; %prealloc

                    ;% rtP.uDLookupTable_maxIndex
                    section.data(1).logicalSrcIdx = 181;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.uDLookupTable2_maxIndex
                    section.data(2).logicalSrcIdx = 182;
                    section.data(2).dtTransOffset = 2;

                    ;% rtP.uDLookupTable2_maxIndex_ebipil2bvy
                    section.data(3).logicalSrcIdx = 183;
                    section.data(3).dtTransOffset = 4;

                    ;% rtP.uDLookupTable2_maxIndex_pobosuq2zq
                    section.data(4).logicalSrcIdx = 184;
                    section.data(4).dtTransOffset = 6;

                    ;% rtP.uDLookupTable_maxIndex_amrotqgr0w
                    section.data(5).logicalSrcIdx = 185;
                    section.data(5).dtTransOffset = 8;

                    ;% rtP.uDLookupTable2_maxIndex_ljaygbg3k3
                    section.data(6).logicalSrcIdx = 186;
                    section.data(6).dtTransOffset = 10;

                    ;% rtP.uDLookupTable2_maxIndex_iu5fpwg5m1
                    section.data(7).logicalSrcIdx = 187;
                    section.data(7).dtTransOffset = 12;

                    ;% rtP.uDLookupTable_maxIndex_c0gevfgaga
                    section.data(8).logicalSrcIdx = 188;
                    section.data(8).dtTransOffset = 14;

                    ;% rtP.DA50TorqueMap_maxIndex
                    section.data(9).logicalSrcIdx = 189;
                    section.data(9).dtTransOffset = 16;

                    ;% rtP.DA50PowerMap_maxIndex
                    section.data(10).logicalSrcIdx = 190;
                    section.data(10).dtTransOffset = 18;

                    ;% rtP.EngTrqTable_maxIndex
                    section.data(11).logicalSrcIdx = 191;
                    section.data(11).dtTransOffset = 20;

                    ;% rtP.FuelMassFlwTable_maxIndex
                    section.data(12).logicalSrcIdx = 192;
                    section.data(12).dtTransOffset = 22;

                    ;% rtP.R_maxIndex
                    section.data(13).logicalSrcIdx = 193;
                    section.data(13).dtTransOffset = 24;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% rtP.Switch3_Threshold
                    section.data(1).logicalSrcIdx = 194;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.Switch3_Threshold_ff0k22oeft
                    section.data(2).logicalSrcIdx = 195;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.ManualSwitch3_CurrentSetting
                    section.data(3).logicalSrcIdx = 196;
                    section.data(3).dtTransOffset = 2;

                    ;% rtP.ManualSwitch2_CurrentSetting
                    section.data(4).logicalSrcIdx = 197;
                    section.data(4).dtTransOffset = 3;

                    ;% rtP.ManualSwitch_CurrentSetting
                    section.data(5).logicalSrcIdx = 198;
                    section.data(5).dtTransOffset = 4;

                    ;% rtP.ManualSwitch1_CurrentSetting
                    section.data(6).logicalSrcIdx = 199;
                    section.data(6).dtTransOffset = 5;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
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
            section.nData     = 142;
            section.data(142)  = dumData; %prealloc

                    ;% rtB.irttg002ix
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.au0ix1q5sj
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% rtB.ix0ijjsadq
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% rtB.i4tiig10qa
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% rtB.mxgpxbyfng
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% rtB.kyvpkfkfuw
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 8;

                    ;% rtB.m12o31k1vs
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 13;

                    ;% rtB.iavmf0c0td
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 15;

                    ;% rtB.g1be22q2ab
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 16;

                    ;% rtB.akjx0hsfge
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 20;

                    ;% rtB.a51hahehmm
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 24;

                    ;% rtB.ivfnl2doo0
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 26;

                    ;% rtB.cftqthzuab
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 27;

                    ;% rtB.e4wlihh0yp
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 28;

                    ;% rtB.m3wbmdk01n
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 29;

                    ;% rtB.cq2d2pwdt4
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 30;

                    ;% rtB.cxcy4qomm3
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 31;

                    ;% rtB.gmqd0r1s5n
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 32;

                    ;% rtB.dnk2tludg2
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 33;

                    ;% rtB.jhai0ek5up
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 34;

                    ;% rtB.nwoetve5i4
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 38;

                    ;% rtB.ea1x0lvxve
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 42;

                    ;% rtB.beedf1ybtr
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 43;

                    ;% rtB.hq4mhr11mq
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 44;

                    ;% rtB.mqvpg31jlu
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 45;

                    ;% rtB.a4b4l1echj
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 46;

                    ;% rtB.eqqz4ci0tv
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 47;

                    ;% rtB.fdtuj3yfv3
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 48;

                    ;% rtB.ka3c0rpnqg
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 49;

                    ;% rtB.nt4pl2mpy0
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 50;

                    ;% rtB.mpbv3fozuy
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 51;

                    ;% rtB.k2emjlyzxk
                    section.data(32).logicalSrcIdx = 31;
                    section.data(32).dtTransOffset = 52;

                    ;% rtB.ahrdefsall
                    section.data(33).logicalSrcIdx = 32;
                    section.data(33).dtTransOffset = 53;

                    ;% rtB.csh2m1cgxy
                    section.data(34).logicalSrcIdx = 33;
                    section.data(34).dtTransOffset = 54;

                    ;% rtB.a5w4q3xmqj
                    section.data(35).logicalSrcIdx = 34;
                    section.data(35).dtTransOffset = 55;

                    ;% rtB.kgbpab1bft
                    section.data(36).logicalSrcIdx = 35;
                    section.data(36).dtTransOffset = 56;

                    ;% rtB.nufjeirxpo
                    section.data(37).logicalSrcIdx = 36;
                    section.data(37).dtTransOffset = 57;

                    ;% rtB.ii512bfhkj
                    section.data(38).logicalSrcIdx = 37;
                    section.data(38).dtTransOffset = 58;

                    ;% rtB.prxcefcei5
                    section.data(39).logicalSrcIdx = 38;
                    section.data(39).dtTransOffset = 59;

                    ;% rtB.ocvt3xrn00
                    section.data(40).logicalSrcIdx = 39;
                    section.data(40).dtTransOffset = 60;

                    ;% rtB.ht0sdc4e2n
                    section.data(41).logicalSrcIdx = 40;
                    section.data(41).dtTransOffset = 61;

                    ;% rtB.nfsnsrxlvr
                    section.data(42).logicalSrcIdx = 41;
                    section.data(42).dtTransOffset = 62;

                    ;% rtB.j14q1l0ljs
                    section.data(43).logicalSrcIdx = 42;
                    section.data(43).dtTransOffset = 63;

                    ;% rtB.fpnl3wyn4z
                    section.data(44).logicalSrcIdx = 43;
                    section.data(44).dtTransOffset = 66;

                    ;% rtB.krukbv1au2
                    section.data(45).logicalSrcIdx = 44;
                    section.data(45).dtTransOffset = 67;

                    ;% rtB.krguxydvse
                    section.data(46).logicalSrcIdx = 45;
                    section.data(46).dtTransOffset = 68;

                    ;% rtB.lufxmyxbr0
                    section.data(47).logicalSrcIdx = 46;
                    section.data(47).dtTransOffset = 69;

                    ;% rtB.ivjcnxt5l0
                    section.data(48).logicalSrcIdx = 47;
                    section.data(48).dtTransOffset = 70;

                    ;% rtB.lxakjhp4ut
                    section.data(49).logicalSrcIdx = 48;
                    section.data(49).dtTransOffset = 71;

                    ;% rtB.cvfcfkbbot
                    section.data(50).logicalSrcIdx = 49;
                    section.data(50).dtTransOffset = 72;

                    ;% rtB.ck20ozhunb
                    section.data(51).logicalSrcIdx = 50;
                    section.data(51).dtTransOffset = 73;

                    ;% rtB.mkzwwcawji
                    section.data(52).logicalSrcIdx = 51;
                    section.data(52).dtTransOffset = 74;

                    ;% rtB.kvxxl1simd
                    section.data(53).logicalSrcIdx = 52;
                    section.data(53).dtTransOffset = 75;

                    ;% rtB.fcdzod43fw
                    section.data(54).logicalSrcIdx = 53;
                    section.data(54).dtTransOffset = 76;

                    ;% rtB.h1yvg3hrrj
                    section.data(55).logicalSrcIdx = 54;
                    section.data(55).dtTransOffset = 77;

                    ;% rtB.i32tsyahbh
                    section.data(56).logicalSrcIdx = 55;
                    section.data(56).dtTransOffset = 78;

                    ;% rtB.c210qvuzpq
                    section.data(57).logicalSrcIdx = 56;
                    section.data(57).dtTransOffset = 79;

                    ;% rtB.nlnobuqb4t
                    section.data(58).logicalSrcIdx = 57;
                    section.data(58).dtTransOffset = 80;

                    ;% rtB.obpp1l4vac
                    section.data(59).logicalSrcIdx = 58;
                    section.data(59).dtTransOffset = 81;

                    ;% rtB.k21i5spcnm
                    section.data(60).logicalSrcIdx = 59;
                    section.data(60).dtTransOffset = 82;

                    ;% rtB.chctnrcvr3
                    section.data(61).logicalSrcIdx = 60;
                    section.data(61).dtTransOffset = 83;

                    ;% rtB.d44xfr2uxh
                    section.data(62).logicalSrcIdx = 61;
                    section.data(62).dtTransOffset = 84;

                    ;% rtB.ksa4mls0wk
                    section.data(63).logicalSrcIdx = 62;
                    section.data(63).dtTransOffset = 85;

                    ;% rtB.fkufe2dwcc
                    section.data(64).logicalSrcIdx = 63;
                    section.data(64).dtTransOffset = 86;

                    ;% rtB.aarbwzwmur
                    section.data(65).logicalSrcIdx = 64;
                    section.data(65).dtTransOffset = 87;

                    ;% rtB.m3te3eovpd
                    section.data(66).logicalSrcIdx = 65;
                    section.data(66).dtTransOffset = 88;

                    ;% rtB.em2j1rtzfx
                    section.data(67).logicalSrcIdx = 66;
                    section.data(67).dtTransOffset = 89;

                    ;% rtB.baetrfr4r5
                    section.data(68).logicalSrcIdx = 67;
                    section.data(68).dtTransOffset = 90;

                    ;% rtB.k2zygd0izr
                    section.data(69).logicalSrcIdx = 68;
                    section.data(69).dtTransOffset = 91;

                    ;% rtB.m4hxih4mk4
                    section.data(70).logicalSrcIdx = 69;
                    section.data(70).dtTransOffset = 92;

                    ;% rtB.gvb04ezgus
                    section.data(71).logicalSrcIdx = 70;
                    section.data(71).dtTransOffset = 93;

                    ;% rtB.lh5ejoytai
                    section.data(72).logicalSrcIdx = 71;
                    section.data(72).dtTransOffset = 94;

                    ;% rtB.bvlzron2lo
                    section.data(73).logicalSrcIdx = 72;
                    section.data(73).dtTransOffset = 95;

                    ;% rtB.bdpeazbcik
                    section.data(74).logicalSrcIdx = 73;
                    section.data(74).dtTransOffset = 96;

                    ;% rtB.ddcgg2bx0n
                    section.data(75).logicalSrcIdx = 74;
                    section.data(75).dtTransOffset = 97;

                    ;% rtB.dbu1cph3qd
                    section.data(76).logicalSrcIdx = 75;
                    section.data(76).dtTransOffset = 98;

                    ;% rtB.gx1mbhkzzf
                    section.data(77).logicalSrcIdx = 76;
                    section.data(77).dtTransOffset = 99;

                    ;% rtB.kkagvopgxv
                    section.data(78).logicalSrcIdx = 77;
                    section.data(78).dtTransOffset = 100;

                    ;% rtB.jtkb23rkw2
                    section.data(79).logicalSrcIdx = 78;
                    section.data(79).dtTransOffset = 101;

                    ;% rtB.k2zpu1crq0
                    section.data(80).logicalSrcIdx = 79;
                    section.data(80).dtTransOffset = 102;

                    ;% rtB.ceua4sozts
                    section.data(81).logicalSrcIdx = 80;
                    section.data(81).dtTransOffset = 103;

                    ;% rtB.enjx00pe1u
                    section.data(82).logicalSrcIdx = 81;
                    section.data(82).dtTransOffset = 104;

                    ;% rtB.lg5bmspaoy
                    section.data(83).logicalSrcIdx = 82;
                    section.data(83).dtTransOffset = 105;

                    ;% rtB.mi1n1xzbri
                    section.data(84).logicalSrcIdx = 83;
                    section.data(84).dtTransOffset = 106;

                    ;% rtB.ph0oqajh3o
                    section.data(85).logicalSrcIdx = 84;
                    section.data(85).dtTransOffset = 107;

                    ;% rtB.feuebfqypv
                    section.data(86).logicalSrcIdx = 85;
                    section.data(86).dtTransOffset = 108;

                    ;% rtB.foeysnqrik
                    section.data(87).logicalSrcIdx = 86;
                    section.data(87).dtTransOffset = 109;

                    ;% rtB.cgtnywjknf
                    section.data(88).logicalSrcIdx = 87;
                    section.data(88).dtTransOffset = 110;

                    ;% rtB.il1hhqxhtq
                    section.data(89).logicalSrcIdx = 88;
                    section.data(89).dtTransOffset = 111;

                    ;% rtB.gxy0dk5ecd
                    section.data(90).logicalSrcIdx = 89;
                    section.data(90).dtTransOffset = 112;

                    ;% rtB.fkz44ny3ao
                    section.data(91).logicalSrcIdx = 90;
                    section.data(91).dtTransOffset = 113;

                    ;% rtB.max0cti2zd
                    section.data(92).logicalSrcIdx = 91;
                    section.data(92).dtTransOffset = 114;

                    ;% rtB.h4fmwxdtzw
                    section.data(93).logicalSrcIdx = 92;
                    section.data(93).dtTransOffset = 115;

                    ;% rtB.ct0fhunmet
                    section.data(94).logicalSrcIdx = 93;
                    section.data(94).dtTransOffset = 116;

                    ;% rtB.ludaotrnqc
                    section.data(95).logicalSrcIdx = 94;
                    section.data(95).dtTransOffset = 117;

                    ;% rtB.fyijl5q30k
                    section.data(96).logicalSrcIdx = 95;
                    section.data(96).dtTransOffset = 118;

                    ;% rtB.dmu1xpyaah
                    section.data(97).logicalSrcIdx = 96;
                    section.data(97).dtTransOffset = 119;

                    ;% rtB.jem0p5cmwo
                    section.data(98).logicalSrcIdx = 97;
                    section.data(98).dtTransOffset = 120;

                    ;% rtB.h1oufun4jj
                    section.data(99).logicalSrcIdx = 98;
                    section.data(99).dtTransOffset = 121;

                    ;% rtB.ary5hhvnmx
                    section.data(100).logicalSrcIdx = 99;
                    section.data(100).dtTransOffset = 122;

                    ;% rtB.obnipod5vd
                    section.data(101).logicalSrcIdx = 100;
                    section.data(101).dtTransOffset = 123;

                    ;% rtB.hcl3f2ypn0
                    section.data(102).logicalSrcIdx = 101;
                    section.data(102).dtTransOffset = 124;

                    ;% rtB.btuvjnvywk
                    section.data(103).logicalSrcIdx = 102;
                    section.data(103).dtTransOffset = 125;

                    ;% rtB.ja5xj0z1cg
                    section.data(104).logicalSrcIdx = 103;
                    section.data(104).dtTransOffset = 126;

                    ;% rtB.kumjwk2t03
                    section.data(105).logicalSrcIdx = 104;
                    section.data(105).dtTransOffset = 127;

                    ;% rtB.g122wtg0el
                    section.data(106).logicalSrcIdx = 105;
                    section.data(106).dtTransOffset = 128;

                    ;% rtB.fhuegjob4p
                    section.data(107).logicalSrcIdx = 106;
                    section.data(107).dtTransOffset = 129;

                    ;% rtB.avg1hsnek4
                    section.data(108).logicalSrcIdx = 107;
                    section.data(108).dtTransOffset = 130;

                    ;% rtB.lo0fmxamwn
                    section.data(109).logicalSrcIdx = 108;
                    section.data(109).dtTransOffset = 131;

                    ;% rtB.bykovcr4gn
                    section.data(110).logicalSrcIdx = 109;
                    section.data(110).dtTransOffset = 132;

                    ;% rtB.ml5chi14gx
                    section.data(111).logicalSrcIdx = 110;
                    section.data(111).dtTransOffset = 133;

                    ;% rtB.favitckluv
                    section.data(112).logicalSrcIdx = 111;
                    section.data(112).dtTransOffset = 134;

                    ;% rtB.fjud52gekg
                    section.data(113).logicalSrcIdx = 112;
                    section.data(113).dtTransOffset = 135;

                    ;% rtB.frdjc0ipbc
                    section.data(114).logicalSrcIdx = 113;
                    section.data(114).dtTransOffset = 147;

                    ;% rtB.pomgrq4ofk
                    section.data(115).logicalSrcIdx = 114;
                    section.data(115).dtTransOffset = 148;

                    ;% rtB.lthpnqg4ps
                    section.data(116).logicalSrcIdx = 115;
                    section.data(116).dtTransOffset = 149;

                    ;% rtB.m4bwkc5hnn
                    section.data(117).logicalSrcIdx = 116;
                    section.data(117).dtTransOffset = 150;

                    ;% rtB.ennxpj0tru
                    section.data(118).logicalSrcIdx = 117;
                    section.data(118).dtTransOffset = 151;

                    ;% rtB.n3yzlaao40
                    section.data(119).logicalSrcIdx = 118;
                    section.data(119).dtTransOffset = 163;

                    ;% rtB.ctnwpqizmx
                    section.data(120).logicalSrcIdx = 119;
                    section.data(120).dtTransOffset = 164;

                    ;% rtB.o1uhppc0j4
                    section.data(121).logicalSrcIdx = 120;
                    section.data(121).dtTransOffset = 165;

                    ;% rtB.gg2bbcdrrw
                    section.data(122).logicalSrcIdx = 121;
                    section.data(122).dtTransOffset = 166;

                    ;% rtB.gssztf5fdg
                    section.data(123).logicalSrcIdx = 123;
                    section.data(123).dtTransOffset = 167;

                    ;% rtB.m5zlrndttj
                    section.data(124).logicalSrcIdx = 124;
                    section.data(124).dtTransOffset = 168;

                    ;% rtB.hzgfvz42dk
                    section.data(125).logicalSrcIdx = 125;
                    section.data(125).dtTransOffset = 169;

                    ;% rtB.h2k2rk41bt
                    section.data(126).logicalSrcIdx = 126;
                    section.data(126).dtTransOffset = 170;

                    ;% rtB.gnyyc12ptg
                    section.data(127).logicalSrcIdx = 127;
                    section.data(127).dtTransOffset = 171;

                    ;% rtB.jjopdzn0py
                    section.data(128).logicalSrcIdx = 128;
                    section.data(128).dtTransOffset = 172;

                    ;% rtB.hbxfzslsut
                    section.data(129).logicalSrcIdx = 129;
                    section.data(129).dtTransOffset = 173;

                    ;% rtB.enyymmluck
                    section.data(130).logicalSrcIdx = 130;
                    section.data(130).dtTransOffset = 174;

                    ;% rtB.nhto33wndj
                    section.data(131).logicalSrcIdx = 131;
                    section.data(131).dtTransOffset = 175;

                    ;% rtB.cguxiwph41
                    section.data(132).logicalSrcIdx = 132;
                    section.data(132).dtTransOffset = 176;

                    ;% rtB.d0ddtqwuj5
                    section.data(133).logicalSrcIdx = 133;
                    section.data(133).dtTransOffset = 177;

                    ;% rtB.olw4ikbxkg
                    section.data(134).logicalSrcIdx = 134;
                    section.data(134).dtTransOffset = 178;

                    ;% rtB.mxxpbb3p2w
                    section.data(135).logicalSrcIdx = 135;
                    section.data(135).dtTransOffset = 179;

                    ;% rtB.jhwxdwr1el
                    section.data(136).logicalSrcIdx = 136;
                    section.data(136).dtTransOffset = 180;

                    ;% rtB.itamdryrgl
                    section.data(137).logicalSrcIdx = 137;
                    section.data(137).dtTransOffset = 181;

                    ;% rtB.fxbpkblr2q
                    section.data(138).logicalSrcIdx = 138;
                    section.data(138).dtTransOffset = 182;

                    ;% rtB.m4c5zvfilf
                    section.data(139).logicalSrcIdx = 139;
                    section.data(139).dtTransOffset = 183;

                    ;% rtB.otltqoc5al
                    section.data(140).logicalSrcIdx = 140;
                    section.data(140).dtTransOffset = 187;

                    ;% rtB.ev0c2l5p3p
                    section.data(141).logicalSrcIdx = 141;
                    section.data(141).dtTransOffset = 188;

                    ;% rtB.hg3boogiog
                    section.data(142).logicalSrcIdx = 142;
                    section.data(142).dtTransOffset = 189;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% rtB.kt4qdvgqqh
                    section.data(1).logicalSrcIdx = 143;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.oudpsgugrl
                    section.data(2).logicalSrcIdx = 144;
                    section.data(2).dtTransOffset = 1;

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
        nTotSects     = 8;
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
            section.nData     = 20;
            section.data(20)  = dumData; %prealloc

                    ;% rtDW.hjhhmazifh
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.oudbjq0hed
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.m4v13avdck
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.a0ptfrtioc
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.g3lob33pj5
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.pyb4n2kdpt
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% rtDW.e3d0a5oz4x
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% rtDW.pgf331hvhc
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

                    ;% rtDW.bxrcqiwwif
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 8;

                    ;% rtDW.hbjtppjnxc
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 9;

                    ;% rtDW.oajcj2f1f5
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 10;

                    ;% rtDW.jny3tr51z3
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 11;

                    ;% rtDW.hvgg13kj3s
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 12;

                    ;% rtDW.k1fhodjxic
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 13;

                    ;% rtDW.l5far1dd5s
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 14;

                    ;% rtDW.dgpg4jadhr
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 15;

                    ;% rtDW.aij0ldcei4
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 16;

                    ;% rtDW.cfefmj5zwg
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 17;

                    ;% rtDW.cern2voaws
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 18;

                    ;% rtDW.htxaynbdci
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 19;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 54;
            section.data(54)  = dumData; %prealloc

                    ;% rtDW.etki2a0fmr.LoggedData
                    section.data(1).logicalSrcIdx = 20;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.bw5y0i4p2l.TimePtr
                    section.data(2).logicalSrcIdx = 21;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.j5biz3l2tk
                    section.data(3).logicalSrcIdx = 22;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.i1wgzi3jpe
                    section.data(4).logicalSrcIdx = 23;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.bob4xgg01l
                    section.data(5).logicalSrcIdx = 24;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.mpzxqeukhd
                    section.data(6).logicalSrcIdx = 25;
                    section.data(6).dtTransOffset = 5;

                    ;% rtDW.fcg0ekphtg
                    section.data(7).logicalSrcIdx = 26;
                    section.data(7).dtTransOffset = 6;

                    ;% rtDW.mvpr3sjc4r
                    section.data(8).logicalSrcIdx = 27;
                    section.data(8).dtTransOffset = 7;

                    ;% rtDW.bakhwucptv
                    section.data(9).logicalSrcIdx = 28;
                    section.data(9).dtTransOffset = 8;

                    ;% rtDW.fzbhykh1xq
                    section.data(10).logicalSrcIdx = 29;
                    section.data(10).dtTransOffset = 9;

                    ;% rtDW.jhafhymz3x
                    section.data(11).logicalSrcIdx = 30;
                    section.data(11).dtTransOffset = 10;

                    ;% rtDW.j5cfxvshqy
                    section.data(12).logicalSrcIdx = 31;
                    section.data(12).dtTransOffset = 11;

                    ;% rtDW.jeli2jkiuj
                    section.data(13).logicalSrcIdx = 32;
                    section.data(13).dtTransOffset = 12;

                    ;% rtDW.pzexosznjb
                    section.data(14).logicalSrcIdx = 33;
                    section.data(14).dtTransOffset = 13;

                    ;% rtDW.j1r4xwoi0i
                    section.data(15).logicalSrcIdx = 34;
                    section.data(15).dtTransOffset = 14;

                    ;% rtDW.fsqmnkfwyn
                    section.data(16).logicalSrcIdx = 35;
                    section.data(16).dtTransOffset = 15;

                    ;% rtDW.gn0zhdovru
                    section.data(17).logicalSrcIdx = 36;
                    section.data(17).dtTransOffset = 16;

                    ;% rtDW.boku4grpzp
                    section.data(18).logicalSrcIdx = 37;
                    section.data(18).dtTransOffset = 17;

                    ;% rtDW.iakvzasvoq
                    section.data(19).logicalSrcIdx = 38;
                    section.data(19).dtTransOffset = 18;

                    ;% rtDW.hrke45uylg
                    section.data(20).logicalSrcIdx = 39;
                    section.data(20).dtTransOffset = 19;

                    ;% rtDW.f5g5n2hoel
                    section.data(21).logicalSrcIdx = 40;
                    section.data(21).dtTransOffset = 20;

                    ;% rtDW.kt3tl4tehf
                    section.data(22).logicalSrcIdx = 41;
                    section.data(22).dtTransOffset = 21;

                    ;% rtDW.jhtpgte2wi.TimePtr
                    section.data(23).logicalSrcIdx = 42;
                    section.data(23).dtTransOffset = 22;

                    ;% rtDW.hvxajhbgno.TimePtr
                    section.data(24).logicalSrcIdx = 43;
                    section.data(24).dtTransOffset = 23;

                    ;% rtDW.fr1mfxzf32.TimePtr
                    section.data(25).logicalSrcIdx = 44;
                    section.data(25).dtTransOffset = 24;

                    ;% rtDW.p2ezmuppnc
                    section.data(26).logicalSrcIdx = 45;
                    section.data(26).dtTransOffset = 25;

                    ;% rtDW.hedrhiezbd
                    section.data(27).logicalSrcIdx = 46;
                    section.data(27).dtTransOffset = 26;

                    ;% rtDW.d21wvb0imp
                    section.data(28).logicalSrcIdx = 47;
                    section.data(28).dtTransOffset = 27;

                    ;% rtDW.oyqqlrp3de
                    section.data(29).logicalSrcIdx = 48;
                    section.data(29).dtTransOffset = 28;

                    ;% rtDW.mmqzqkgwoq
                    section.data(30).logicalSrcIdx = 49;
                    section.data(30).dtTransOffset = 29;

                    ;% rtDW.dfna2oq4ag
                    section.data(31).logicalSrcIdx = 50;
                    section.data(31).dtTransOffset = 30;

                    ;% rtDW.llxxjvefz5
                    section.data(32).logicalSrcIdx = 51;
                    section.data(32).dtTransOffset = 31;

                    ;% rtDW.ayv1jfdv3n
                    section.data(33).logicalSrcIdx = 52;
                    section.data(33).dtTransOffset = 32;

                    ;% rtDW.dg2tvdaeix
                    section.data(34).logicalSrcIdx = 53;
                    section.data(34).dtTransOffset = 33;

                    ;% rtDW.mdrultrm3a
                    section.data(35).logicalSrcIdx = 54;
                    section.data(35).dtTransOffset = 34;

                    ;% rtDW.cvkblbg5ng.LoggedData
                    section.data(36).logicalSrcIdx = 55;
                    section.data(36).dtTransOffset = 35;

                    ;% rtDW.pd5drfuyof.LoggedData
                    section.data(37).logicalSrcIdx = 56;
                    section.data(37).dtTransOffset = 38;

                    ;% rtDW.d3le14d3cp.LoggedData
                    section.data(38).logicalSrcIdx = 57;
                    section.data(38).dtTransOffset = 39;

                    ;% rtDW.kjvolenzbx.LoggedData
                    section.data(39).logicalSrcIdx = 58;
                    section.data(39).dtTransOffset = 40;

                    ;% rtDW.pene5pwpkv.LoggedData
                    section.data(40).logicalSrcIdx = 59;
                    section.data(40).dtTransOffset = 41;

                    ;% rtDW.jo5onp05oj.LoggedData
                    section.data(41).logicalSrcIdx = 60;
                    section.data(41).dtTransOffset = 42;

                    ;% rtDW.jsi4xupntz.LoggedData
                    section.data(42).logicalSrcIdx = 61;
                    section.data(42).dtTransOffset = 43;

                    ;% rtDW.pbrgjp3hqd.LoggedData
                    section.data(43).logicalSrcIdx = 62;
                    section.data(43).dtTransOffset = 46;

                    ;% rtDW.gnxi5omu0q.LoggedData
                    section.data(44).logicalSrcIdx = 63;
                    section.data(44).dtTransOffset = 47;

                    ;% rtDW.ay2vulzcxm.LoggedData
                    section.data(45).logicalSrcIdx = 64;
                    section.data(45).dtTransOffset = 48;

                    ;% rtDW.n0zwk3f2xj.LoggedData
                    section.data(46).logicalSrcIdx = 65;
                    section.data(46).dtTransOffset = 49;

                    ;% rtDW.dwk0spdowz.LoggedData
                    section.data(47).logicalSrcIdx = 66;
                    section.data(47).dtTransOffset = 50;

                    ;% rtDW.ppi2an01a4.LoggedData
                    section.data(48).logicalSrcIdx = 67;
                    section.data(48).dtTransOffset = 54;

                    ;% rtDW.k5h4rh0ide.LoggedData
                    section.data(49).logicalSrcIdx = 68;
                    section.data(49).dtTransOffset = 58;

                    ;% rtDW.coy5zsehq2.LoggedData
                    section.data(50).logicalSrcIdx = 69;
                    section.data(50).dtTransOffset = 60;

                    ;% rtDW.bslxcnpnbe.LoggedData
                    section.data(51).logicalSrcIdx = 70;
                    section.data(51).dtTransOffset = 61;

                    ;% rtDW.oudcefeijx.LoggedData
                    section.data(52).logicalSrcIdx = 71;
                    section.data(52).dtTransOffset = 62;

                    ;% rtDW.ngauttml0y.LoggedData
                    section.data(53).logicalSrcIdx = 72;
                    section.data(53).dtTransOffset = 64;

                    ;% rtDW.aruc1k5fox.LoggedData
                    section.data(54).logicalSrcIdx = 73;
                    section.data(54).dtTransOffset = 66;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 14;
            section.data(14)  = dumData; %prealloc

                    ;% rtDW.jclc1m30fx
                    section.data(1).logicalSrcIdx = 74;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.d05f353xni.PrevIndex
                    section.data(2).logicalSrcIdx = 75;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.bmyjja4qwv
                    section.data(3).logicalSrcIdx = 76;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.dorteqrwse
                    section.data(4).logicalSrcIdx = 77;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.n0n2vuipdf
                    section.data(5).logicalSrcIdx = 78;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.ke0t5lasbz
                    section.data(6).logicalSrcIdx = 79;
                    section.data(6).dtTransOffset = 5;

                    ;% rtDW.jcqddiyhqh.PrevIndex
                    section.data(7).logicalSrcIdx = 80;
                    section.data(7).dtTransOffset = 6;

                    ;% rtDW.eixvkodrjc.PrevIndex
                    section.data(8).logicalSrcIdx = 81;
                    section.data(8).dtTransOffset = 7;

                    ;% rtDW.dtpp4iwgtx.PrevIndex
                    section.data(9).logicalSrcIdx = 82;
                    section.data(9).dtTransOffset = 8;

                    ;% rtDW.k5a5eyevvp
                    section.data(10).logicalSrcIdx = 83;
                    section.data(10).dtTransOffset = 9;

                    ;% rtDW.l4dxiaonqg
                    section.data(11).logicalSrcIdx = 84;
                    section.data(11).dtTransOffset = 10;

                    ;% rtDW.b2vnrg1jny
                    section.data(12).logicalSrcIdx = 85;
                    section.data(12).dtTransOffset = 11;

                    ;% rtDW.ewedjye3z0
                    section.data(13).logicalSrcIdx = 86;
                    section.data(13).dtTransOffset = 12;

                    ;% rtDW.d24a3iy2yr
                    section.data(14).logicalSrcIdx = 87;
                    section.data(14).dtTransOffset = 13;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% rtDW.nr541hf2w4
                    section.data(1).logicalSrcIdx = 88;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.jueswsqa1v
                    section.data(2).logicalSrcIdx = 89;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.cndm4gb520
                    section.data(3).logicalSrcIdx = 90;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 30;
            section.data(30)  = dumData; %prealloc

                    ;% rtDW.g5r1yktyf0
                    section.data(1).logicalSrcIdx = 91;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.pitowdgxye
                    section.data(2).logicalSrcIdx = 92;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.fxz4zvrdnk
                    section.data(3).logicalSrcIdx = 93;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.efurz0y3yi
                    section.data(4).logicalSrcIdx = 94;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.pii1ltmep3
                    section.data(5).logicalSrcIdx = 95;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.jsvlghnnou
                    section.data(6).logicalSrcIdx = 96;
                    section.data(6).dtTransOffset = 5;

                    ;% rtDW.mwn40uclws
                    section.data(7).logicalSrcIdx = 97;
                    section.data(7).dtTransOffset = 6;

                    ;% rtDW.bnrzbkqovy
                    section.data(8).logicalSrcIdx = 98;
                    section.data(8).dtTransOffset = 7;

                    ;% rtDW.hsbxk4y5en
                    section.data(9).logicalSrcIdx = 99;
                    section.data(9).dtTransOffset = 8;

                    ;% rtDW.fs2zaamasz
                    section.data(10).logicalSrcIdx = 100;
                    section.data(10).dtTransOffset = 9;

                    ;% rtDW.apx4aufauy
                    section.data(11).logicalSrcIdx = 101;
                    section.data(11).dtTransOffset = 10;

                    ;% rtDW.i0u0wqsccx
                    section.data(12).logicalSrcIdx = 102;
                    section.data(12).dtTransOffset = 11;

                    ;% rtDW.bomurwpyov
                    section.data(13).logicalSrcIdx = 103;
                    section.data(13).dtTransOffset = 12;

                    ;% rtDW.mjf1zdwwpb
                    section.data(14).logicalSrcIdx = 104;
                    section.data(14).dtTransOffset = 13;

                    ;% rtDW.aeu2i4j0ln
                    section.data(15).logicalSrcIdx = 105;
                    section.data(15).dtTransOffset = 14;

                    ;% rtDW.dd5lqxkqw1
                    section.data(16).logicalSrcIdx = 106;
                    section.data(16).dtTransOffset = 15;

                    ;% rtDW.pkdoeu3vac
                    section.data(17).logicalSrcIdx = 107;
                    section.data(17).dtTransOffset = 16;

                    ;% rtDW.iuutt5gbfx
                    section.data(18).logicalSrcIdx = 108;
                    section.data(18).dtTransOffset = 17;

                    ;% rtDW.ifu2rmppxs
                    section.data(19).logicalSrcIdx = 109;
                    section.data(19).dtTransOffset = 18;

                    ;% rtDW.fe1jlxthwc
                    section.data(20).logicalSrcIdx = 110;
                    section.data(20).dtTransOffset = 19;

                    ;% rtDW.jbdxmczt2f
                    section.data(21).logicalSrcIdx = 111;
                    section.data(21).dtTransOffset = 20;

                    ;% rtDW.lpzxn11asy
                    section.data(22).logicalSrcIdx = 112;
                    section.data(22).dtTransOffset = 21;

                    ;% rtDW.miza0bwslu
                    section.data(23).logicalSrcIdx = 113;
                    section.data(23).dtTransOffset = 22;

                    ;% rtDW.okv3jznoxf
                    section.data(24).logicalSrcIdx = 114;
                    section.data(24).dtTransOffset = 23;

                    ;% rtDW.ns1xtz2b4p
                    section.data(25).logicalSrcIdx = 115;
                    section.data(25).dtTransOffset = 24;

                    ;% rtDW.k11uca0ow3
                    section.data(26).logicalSrcIdx = 116;
                    section.data(26).dtTransOffset = 25;

                    ;% rtDW.byziukqaaz
                    section.data(27).logicalSrcIdx = 117;
                    section.data(27).dtTransOffset = 26;

                    ;% rtDW.fn0wimupx0
                    section.data(28).logicalSrcIdx = 118;
                    section.data(28).dtTransOffset = 27;

                    ;% rtDW.cgq2mdkand
                    section.data(29).logicalSrcIdx = 119;
                    section.data(29).dtTransOffset = 28;

                    ;% rtDW.auskljzuj1
                    section.data(30).logicalSrcIdx = 120;
                    section.data(30).dtTransOffset = 29;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 7;
            section.data(7)  = dumData; %prealloc

                    ;% rtDW.gnqj1fyav2
                    section.data(1).logicalSrcIdx = 121;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.hembao2eny
                    section.data(2).logicalSrcIdx = 122;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.lbv1klntc2
                    section.data(3).logicalSrcIdx = 123;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.a2nmjrkqqq
                    section.data(4).logicalSrcIdx = 124;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.jnjyibka5j
                    section.data(5).logicalSrcIdx = 125;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.kkz3bigo3a
                    section.data(6).logicalSrcIdx = 126;
                    section.data(6).dtTransOffset = 5;

                    ;% rtDW.iy5ftg1sqh
                    section.data(7).logicalSrcIdx = 127;
                    section.data(7).dtTransOffset = 6;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.n0kqgy2htn.iibbwx5nxu
                    section.data(1).logicalSrcIdx = 128;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(7) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.l55fduec5sc.iibbwx5nxu
                    section.data(1).logicalSrcIdx = 129;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(8) = section;
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


    targMap.checksum0 = 3064774813;
    targMap.checksum1 = 227680994;
    targMap.checksum2 = 1504209091;
    targMap.checksum3 = 2416809870;

