# TODO

Текущее состояние: 4.14.357 + KernelSU-Next v3.2.0-legacy (11aea3eb) + susfs v1.5.5, DT2W, Magic Mount.
Свежий boot.img: `/tmp/opencode/nabu-ksu-susfs-boot.img`.

## После прошивки (тест текущего ядра)
- [ ] Прошить: `fastboot flash boot_a /tmp/opencode/nabu-ksu-susfs-boot.img`
- [ ] Проверить загрузку, рут (KernelSU-Next Manager, `ksud`), DT2W
- [ ] Проверить susfs: `lsusfs`, `ksu_susfs --sus-path /system /vendor` (повторять после каждого обновления ROM)
- [ ] Magic Mount: убедиться, что `/debug_ramdisk/workdir` работает
- [ ] Проверить, что аудио работает (techpack вшит), камеры, GPS, BT/WiFi

## Патчи/твики на потом (по желанию)
- [ ] GPU OC: Adreno 618 514 -> 750 МГц (`qcom,gpu-pwrlevel@0` в `arch/arm64/boot/dts/qcom/sdmshrike-gpu.dtsi`) — безопасно, + ступени при желании
- [ ] CPU OC: аккуратно до 2.3–2.4 ГГц (`qcom,cpufreq-table-7` в `arch/arm64/boot/dts/qcom/sm8150-v2.dtsi`) — риск нестабильности, выше 2.2 ГГц железо не гарантирует
- [ ] Терм: поднять CPU trip'ы 115 -> 120 °C (`arch/arm64/boot/dts/qcom/sdmshrike-thermal.dtsi`), смягчить cooling-maps (`sm8150-thermal-overlay.dtsi`)
- [ ] Главный троттлер — vendor `thermal-engine.conf` (`/vendor/etc/`), правится на устройстве после рута
- [ ] KVM: включить (config-only) -> проверить `/dev/kvm` и `dmesg | grep -i kvm` (нужен свободный EL2; pKVM на 4.14 не существует)
- [ ] USB-WiFi драйверы (ath9k_htc, rtl8xxxu, mt7601u, rt2x00, carl9170) — конфиг-онли, если понадобится
- [ ] USB HID gadget: configfs (CONFIG_USB_CONFIGFS_F_HID уже включён) — `/dev/hidg0`
- [ ] Флаги оптимизации (-O3, -march): только после бенчмарков, выигрыш мал (LTO уже включён)

## Обновления
- [ ] KernelSU-Next: при новых тегах — `git submodule update`, ветка `nabu`, пересборка
- [ ] susfs: следить за релизами, портировать изменения поверх наших хуков (namei/task_mmu/fdinfo/proc_namespace)
